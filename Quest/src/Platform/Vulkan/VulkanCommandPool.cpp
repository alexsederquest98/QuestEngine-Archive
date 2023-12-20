#include "qepch.h"
#include "VulkanCommandPool.h"

namespace Quest
{
	VulkanCommandPool::VulkanCommandPool(RefPtr<VulkanDevice> device)
		: m_Device(device)
	{
		// Create the graphics command queue
		auto queueFamilyIndices = device->GetPhysicalDevice()->GetQueueFamilies();
		
		VkCommandPoolCreateInfo poolInfo{};
		poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
		poolInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
		poolInfo.queueFamilyIndex = queueFamilyIndices.graphicsFamily.value();

		if (vkCreateCommandPool(device->GetDevice(), &poolInfo, nullptr, &m_GraphicsCommandPool) != VK_SUCCESS)
		{
			QE_CORE_FATAL("Failed to create Vulkan command pool");
		}
	}

	VulkanCommandPool::~VulkanCommandPool()
	{
		vkDestroyCommandPool(m_Device->GetDevice(), m_GraphicsCommandPool, nullptr);
	}

	VkCommandBuffer VulkanCommandPool::AllocateCommandBuffer()
	{
		auto vulkanDevice = m_Device->GetDevice();

		VkCommandBufferAllocateInfo allocInfo{};
		allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
		allocInfo.commandPool = m_GraphicsCommandPool;
		allocInfo.commandBufferCount = 1;

		VkCommandBuffer commandBuffer;
		vkAllocateCommandBuffers(vulkanDevice, &allocInfo, &commandBuffer);

		return commandBuffer;
	}

	void VulkanCommandPool::FlushCommandBuffer(VkCommandBuffer buffer)
	{
	}

	inline void VulkanCommandPool::BeginCommandBuffer(VkCommandBuffer buffer, bool singleUse)
	{
		VkCommandBufferBeginInfo beginInfo{};
		beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		if (singleUse)
			beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

		vkBeginCommandBuffer(buffer, &beginInfo);
	}

	inline void VulkanCommandPool::EndCommandBuffer(VkCommandBuffer buffer)
	{
		vkEndCommandBuffer(buffer);
	}


}