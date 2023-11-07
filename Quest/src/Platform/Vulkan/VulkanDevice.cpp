#include "qepch.h"
#include "VulkanDevice.h"
#include "VulkanRenderDevice.h"

#include <string>
#include <set>

namespace Quest
{
	const std::vector<const char*> deviceExtensions = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};

	// PHYSICAL DEVICE
	VulkanPhysicalDevice::VulkanPhysicalDevice()
	{
		// Get the instance from the RenderDevice
		auto vk_instance = VulkanRenderDevice::GetInstance();
		// Pick the physical device that best fits
		m_PhysicalDevice = PickPhysicalDevice(vk_instance);
	}

	VulkanPhysicalDevice::~VulkanPhysicalDevice()
	{
	}

	VkPhysicalDevice VulkanPhysicalDevice::PickPhysicalDevice(VkInstance instance)
	{
		uint32 deviceCount = 0;
		vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

		if (deviceCount == 0)
		{
			QE_CORE_FATAL("Failed to find GPUs with Vulkan support");
		}

		std::vector<VkPhysicalDevice> devices(deviceCount);
		vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

		for (const auto& device : devices)
		{
			if (IsDeviceSuitable(device))
			{
				m_PhysicalDevice = device;
				break;
			}
		}

		if (m_PhysicalDevice == VK_NULL_HANDLE)
		{
			QE_CORE_FATAL("No suitable GPU found");
		}

		// Set the info about the physical device chosen
		vkGetPhysicalDeviceProperties(m_PhysicalDevice, &m_Properties);
		vkGetPhysicalDeviceFeatures(m_PhysicalDevice, &m_Features);
		vkGetPhysicalDeviceMemoryProperties(m_PhysicalDevice, &m_MemoryProperties);
	}

	bool VulkanPhysicalDevice::IsDeviceSuitable(VkPhysicalDevice device)
	{
		VkPhysicalDeviceProperties deviceProperties;
		vkGetPhysicalDeviceProperties(device, &deviceProperties);

		QueueFamilyIndices indices = FindQueueFamilies(device);

		bool extensionsSupported = CheckDeviceExtensionSupport(device);

		/*bool swapChainAdequate = false;
		if (extensionsSupported)
		{
			SwapChainSupportDetails swapChainSupport = QuerySwapChainSupport(device);
			swapChainAdequate = !swapChainSupport.formats.empty() && !swapChainSupport.presentModes.empty();
		}*/

		VkPhysicalDeviceFeatures supportedFeatures;
		vkGetPhysicalDeviceFeatures(device, &supportedFeatures);

		return deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU
			&& indices.isComplete() && extensionsSupported && supportedFeatures.samplerAnisotropy;
	}

	bool VulkanPhysicalDevice::CheckDeviceExtensionSupport(VkPhysicalDevice device)
	{
		uint32 extensionCount;
		vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, nullptr);

		std::vector<VkExtensionProperties> availableExtensions(extensionCount);
		vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, availableExtensions.data());

		std::set<std::string> requiredExtensions(deviceExtensions.begin(), deviceExtensions.end());

		for (const auto& extension : availableExtensions)
		{
			requiredExtensions.erase(extension.extensionName);
		}

		return requiredExtensions.empty();
	}

	QueueFamilyIndices VulkanPhysicalDevice::FindQueueFamilies(VkPhysicalDevice device)
	{
		QueueFamilyIndices indices;

		uint32 queueFamilyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

		std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

		int i = 0;
		for (const auto& queueFamily : queueFamilies)
		{
			if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
				indices.graphicsFamily = i;

			if (queueFamily.queueFlags & VK_QUEUE_TRANSFER_BIT)
				indices.transferFamily = i;

			//VkBool32 presentSupport = false;
			//vkGetPhysicalDeviceSurfaceSupportKHR(device, i, m_Surface, &presentSupport);

			//if (presentSupport)
			//	indices.presentFamily = i;

			if (indices.isComplete())
				break;

			i++;
		}

		return indices;
	}

	// LOGICAL DEVICE
}