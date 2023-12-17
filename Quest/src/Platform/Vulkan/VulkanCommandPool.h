#pragma once

#include <vulkan/vulkan.h>

#include "VulkanDevice.h"

namespace Quest
{
	class VulkanCommandPool
	{
	public:
		VulkanCommandPool(Ref<VulkanDevice> device);
		~VulkanCommandPool();

		VkCommandBuffer AllocateCommandBuffer();
		void FlushCommandBuffer(VkCommandBuffer buffer);

		inline void BeginCommandBuffer(VkCommandBuffer buffer, bool singleUse = false);
		inline void EndCommandBuffer(VkCommandBuffer buffer);

		VkCommandPool GetGraphicsCommandPool() const { return m_GraphicsCommandPool; }
	private:
		// Reference to the device, passed by dependency injection
		Ref<VulkanDevice> m_Device;
		VkCommandPool m_GraphicsCommandPool;
	};
}