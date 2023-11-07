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

		const bool GetEnabledValidation();
		const std::vector<const char*> GetValidationLayers();
	private:
		void CreateInstance();
		std::vector<const char*> GetRequiredExtensions();

		void SetupDebugMessenger();
	private:
		inline static VkInstance s_Instance;
		Ref<VulkanPhysicalDevice> m_PhysicalDevice;
		Ref<VulkanDevice> m_Device;

		VkDebugUtilsMessengerEXT m_DebugMessenger;


#ifdef NDEBUG
		const bool enableValidationLayers = false;
#else
		const bool enableValidationLayers = true;
#endif
		const std::vector<const char*> validationLayers = {
			"VK_LAYER_KHRONOS_validation"
		};
	};
}