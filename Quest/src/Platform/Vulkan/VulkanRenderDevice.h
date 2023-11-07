#pragma once

#include "Core/Base.h"
#include "VulkanDevice.h"

#include <vulkan/vulkan.h>

#include <vector>

namespace Quest
{
	class VulkanRenderDevice
	{
	public:
		VulkanRenderDevice();
		~VulkanRenderDevice();

		static VkInstance GetInstance() { return s_Instance; }

		Ref<VulkanDevice> GetDevice() { return m_Device; }
	private:
		void CreateInstance();
		std::vector<const char*> GetRequiredExtensions();

		void SetupDebugMessenger();
	private:
		inline static VkInstance s_Instance;
		//Ref<VulkanPhysicalDevice> m_PhysicalDevice;
		Ref<VulkanDevice> m_Device;

		VkDebugUtilsMessengerEXT m_DebugMessenger;
	};
}