#pragma once
#include "Core/Base.h"

#include <vulkan/vulkan.h>

#include <optional>
#include <vector>

namespace Quest
{
	struct QueueFamilyIndices
	{
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> transferFamily;

		bool isComplete()
		{
			return graphicsFamily.has_value() && transferFamily.has_value();
		}
	};

	// Physical device
	class VulkanPhysicalDevice
	{
	public:
		VulkanPhysicalDevice();
		~VulkanPhysicalDevice();

		const VkPhysicalDeviceProperties& GetProperties() const { return m_Properties; }
		const VkPhysicalDeviceFeatures& GetFeatures() const { return m_Features; }
		const VkPhysicalDeviceMemoryProperties& GetMemoryProperties() const { return m_MemoryProperties; }
	private:
		VkPhysicalDevice PickPhysicalDevice(VkInstance instance);
		bool IsDeviceSuitable(VkPhysicalDevice device);
		bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
		QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
	private:
		VkPhysicalDevice m_PhysicalDevice;
		VkPhysicalDeviceProperties m_Properties;
		VkPhysicalDeviceFeatures m_Features;
		VkPhysicalDeviceMemoryProperties m_MemoryProperties;

		friend class VulkanDevice;
	};

	// The logical device
	class VulkanDevice
	{
	public:
		VulkanDevice();
		~VulkanDevice();
	private:
	private:
		VkDevice m_Device;
		Ref<VulkanPhysicalDevice> m_PhysicalDevice;

		VkQueue m_GraphicsQueue;
		//VkQueue m_ComputeQueue; // NOT USED YET
	};
}