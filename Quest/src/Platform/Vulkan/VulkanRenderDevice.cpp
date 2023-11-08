#include "qepch.h"
#include "VulkanRenderDevice.h"

#include <GLFW/glfw3.h>

namespace Quest
{
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData)
	{
		QE_CORE_DEBUG("Validation Layer: {0}", pCallbackData->pMessage);
		return VK_FALSE;
	}

	// Debug messenger functions
	static void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo)
	{
		createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
		//createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT;
		createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
		createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
		createInfo.pfnUserCallback = debugCallback;
	}

	static bool CheckValidationLayerSupport(const std::vector<const char*> validationLayers)
	{
		uint32 layerCount;
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

		std::vector<VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

		for (const char* layerName : validationLayers)
		{
			bool layerFound = false;

			for (const auto& layerProperties : availableLayers)
			{
				if (strcmp(layerName, layerProperties.layerName) == 0)
				{
					layerFound = true;
					break;
				}
			}

			if (!layerFound)
			{
				return false;
			}
		}

		return true;
	}

	// Debug util stuff
	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger)
	{
		auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
		if (func != nullptr)
		{
			return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
		}
		else
		{
			return VK_ERROR_EXTENSION_NOT_PRESENT;
		}
	}

	void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator)
	{
		auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
		if (func != nullptr)
		{
			func(instance, debugMessenger, pAllocator);
		}
	}

	VulkanRenderDevice::VulkanRenderDevice(const RenderDeviceSpecification& spec)
	{
		m_Window = spec.window;

		QE_CORE_ASSERT_MSG(glfwVulkanSupported(), "GLFW needs to have Vulkan support");
		// Check for vulkan supported version here later

		// Initialize the vulkan instance
		CreateInstance();
		// Setup debug messenger
		SetupDebugMessenger();

		// Select the physical device
		m_PhysicalDevice = VulkanPhysicalDevice::ChoosePhysicalDevice();
		// Create the logical device
		m_Device = VulkanDevice::CreateLogicalDevice(m_PhysicalDevice, validationLayers, enableValidationLayers);

		// Surface and swapchain
		m_SwapChain = CreateRef<VulkanSwapChain>();
		m_SwapChain->Init(s_Instance, m_Device, m_Window);
		m_SwapChain->InitSurface();
	}

	VulkanRenderDevice::~VulkanRenderDevice()
	{
		vkDestroyInstance(s_Instance, nullptr);
		s_Instance = nullptr;
	}

	void VulkanRenderDevice::DrawFrame()
	{
	}

	void VulkanRenderDevice::WaitForDeviceToFinishExecuting()
	{
		// Make this a method in the device later
		vkDeviceWaitIdle(m_Device->GetDevice());
	}

	const bool VulkanRenderDevice::GetEnabledValidation()
	{
		return enableValidationLayers;
	}

	const std::vector<const char*> VulkanRenderDevice::GetValidationLayers()
	{
		return validationLayers;
	}

	void VulkanRenderDevice::CreateInstance()
	{
		if (enableValidationLayers && !CheckValidationLayerSupport(validationLayers))
		{
			QE_CORE_FATAL("Validations layers requested but not available");
		}

		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Quest";
		appInfo.pEngineName = "Quest";
		appInfo.apiVersion = VK_API_VERSION_1_3;

		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		auto extensions = GetRequiredExtensions();
		createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
		createInfo.ppEnabledExtensionNames = extensions.data();

		VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
		if (enableValidationLayers)
		{
			createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
			createInfo.ppEnabledLayerNames = validationLayers.data();

			PopulateDebugMessengerCreateInfo(debugCreateInfo);
			createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
		}
		else
		{
			createInfo.enabledLayerCount = 0;

			createInfo.pNext = nullptr;
		}

		if (vkCreateInstance(&createInfo, nullptr, &s_Instance) != VK_SUCCESS)
		{
			QE_CORE_FATAL("Failed to create Vulkan Instance");
		}
	}

	std::vector<const char*> VulkanRenderDevice::GetRequiredExtensions()
	{
		uint32 glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

		if (enableValidationLayers)
		{
			extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
		}

		return extensions;
	}

	void VulkanRenderDevice::SetupDebugMessenger()
	{
		if (!enableValidationLayers) return;

		VkDebugUtilsMessengerCreateInfoEXT createInfo;
		PopulateDebugMessengerCreateInfo(createInfo);

		if (CreateDebugUtilsMessengerEXT(s_Instance, &createInfo, nullptr, &m_DebugMessenger) != VK_SUCCESS)
		{
			QE_CORE_FATAL("Failed to setup Vulkan debug messenger");
		}
	}
}