#include "qepch.h"
#include "Core/Base.h"
#include "VulkanInstance.h"

#include <vector>

#include <GLFW/glfw3.h>

namespace Quest
{
	VulkanInstance::VulkanInstance()
	{
		// Get how many extensions are supported
		uint32 extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
		QE_CORE_INFO("Vulkan - {0} extensions supported", extensionCount);

		// Log the supported extensions
		std::vector<VkExtensionProperties> extensions(extensionCount);
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
		QE_CORE_INFO("Available Vulkan Extensions:");
		for (const auto& extension : extensions)
			QE_CORE_INFO("\t\t{0}", extension.extensionName);

		//Init();
	}

	VulkanInstance::~VulkanInstance()
	{
		//Shutdown();
	}

	void VulkanInstance::Init()
	{
		// Application info
		VkApplicationInfo appInfo
		{
			.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
			.pApplicationName = "Quest Application",
			.applicationVersion = VK_MAKE_VERSION(1, 0, 0),
			.pEngineName = "Quest Engine",
			.engineVersion = VK_MAKE_VERSION(1, 0, 0),
			.apiVersion = VK_API_VERSION_1_3
		};

		// Extension info
		uint32 glfwExtensionCount = 0;
		const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		// Instance creation info
		VkInstanceCreateInfo createInfo
		{
			.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
			.pApplicationInfo = &appInfo,
			.enabledLayerCount = 0,
			.enabledExtensionCount = glfwExtensionCount,
			.ppEnabledExtensionNames = glfwExtensions
		};

		// Create the instance call
		if (vkCreateInstance(&createInfo, nullptr, &m_Instance) != VK_SUCCESS)
		{
			QE_CORE_FATAL("Failed to create the Vulkan Instance");
		}
		QE_CORE_INFO("Vulkan Instance Created.");

	}

	void VulkanInstance::Shutdown()
	{
		vkDestroyInstance(m_Instance, nullptr);
	}

	VkInstance& VulkanInstance::GetRaw()
	{
		return m_Instance;
	}
}