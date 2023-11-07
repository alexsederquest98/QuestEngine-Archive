#pragma once

#include "Core/Base.h"
#include "VulkanDevice.h"

#include <vulkan/vulkan.h>

namespace Quest
{
	class VulkanRenderDevice
	{
	public:
		VulkanRenderDevice();
		~VulkanRenderDevice();

		static VkInstance GetInstance() { return s_Instance; }
	private:
	private:
		inline static VkInstance s_Instance;
		Ref<VulkanPhysicalDevice> m_PhysicalDevice;
		Ref<VulkanDevice> m_Device;
	};
}