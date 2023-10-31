#pragma once
#include "Core/Base.h"
#include "Renderer/GraphicsDevice.h"

#include <vector>
#include <optional>

#include <vulkan/vulkan.h>

namespace Quest
{
	struct QueueFamilyIndices
	{
		std::optional<uint32> graphicsFamily;
		std::optional<uint32> presentFamily;

		bool isComplete()
		{
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};

	struct SwapChainSupportDetails
	{
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	class VulkanGraphicsDevice : public GraphicsDevice
	{
	public:
		VulkanGraphicsDevice(const GraphicsDeviceSpecification& spec);
		~VulkanGraphicsDevice();

		void DrawFrame() override;
		void WaitForDeviceToFinishExecuting() override;
		void FramebufferResize() override { m_FramebufferResized = true; }
	private:
		void Init(); // Vulkan init function, initialize all the objects required for Vulkan to function
		void Shutdown(); // clean up function

		// Vulkan object creation functions
		void CreateInstance();
		void SetupDebugMessenger();
		void CreateSurface();
		void PickPhysicalDevice();
		void CreateLogicalDevice();
		void CreateSwapChain();
		void CreateImageViews();
		void CreateRenderPass();
		void CreateDescriptorSetLayout();
		void CreateGraphicsPipeline();
		void CreateFramebuffers();
		void CreateCommandPool();
		void CreateTextureImage();
		void CreateVertexBuffer();
		void CreateIndexbuffer();
		void CreateUniformBuffers();
		void CreateDescriptorPool();
		void CreateDescriptorSets();
		void CreateCommandBuffers();
		void CreateSyncObjects();

		// Instance helper
		std::vector<const char*> GetRequiredExtensions();

		// Physical Device helpers
		bool IsDeviceSuitable(VkPhysicalDevice device);
		bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
		QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);

		// Swapchain helpers
		SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);
		VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
		void CleanupSwapChain();
		void RecreateSwapChain();

		// Pipeline/Shader helpers
		std::vector<char> ReadShaderFromFile(const std::string& filename);
		VkShaderModule CreateShaderModule(const std::vector<char>& code);

		// Command buffer  helper
		void RecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
		VkCommandBuffer BeginSingleTimeCommands();
		void EndSingleTimeCommands(VkCommandBuffer commandBuffer);

		// Vertex buffer helpers
		uint32_t FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
		void CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
		void CopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

		// Uniform buffer helpers
		void UpdateUniformBuffer(uint32_t currentImage);

		// Image helper
		void CreateImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
		void TransitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);
		void CopyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);

		// Debug messenger specific functions
		void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
		bool CheckValidationLayerSupport();
		static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData)
		{
			QE_CORE_DEBUG("Validation Layer: {0}", pCallbackData->pMessage);
			return VK_FALSE;
		}

	private:
		VkInstance m_Instance;
		VkDebugUtilsMessengerEXT m_DebugMessenger;
		VkSurfaceKHR m_Surface;

		VkPhysicalDevice m_PhysicalDevice = VK_NULL_HANDLE;
		VkDevice m_Device;

		VkQueue m_GraphicsQueue;
		VkQueue m_PresentQueue;

		VkSwapchainKHR m_SwapChain;
		std::vector<VkImage> m_SwapChainImages;
		VkFormat m_SwapChainImageFormat;
		VkExtent2D m_SwapChainExtent;
		std::vector<VkImageView> m_SwapChainImageViews;
		std::vector<VkFramebuffer> m_SwapChainFramebuffers;

		VkRenderPass m_RenderPass;
		VkDescriptorSetLayout m_DescriptorSetLayout;
		VkPipelineLayout m_PipelineLayout;
		VkPipeline m_GraphicsPipeline;

		VkCommandPool m_CommandPool;
		std::vector<VkCommandBuffer> m_CommandBuffers;

		std::vector<VkSemaphore> m_ImageAvailableSemaphores;
		std::vector<VkSemaphore> m_RenderFinishedSemaphores;
		std::vector<VkFence> m_InFlightFences;

		bool m_FramebufferResized = false;
		uint32_t m_CurrentFrame = 0;

		VkBuffer m_VertexBuffer;
		VkDeviceMemory m_VertexBufferMemory;
		VkBuffer m_IndexBuffer;
		VkDeviceMemory m_IndexBufferMemory;

		std::vector<VkBuffer> m_UniformBuffers;
		std::vector<VkDeviceMemory> m_UniformBuffersMemory;
		std::vector<void*> m_UniformBuffersMapped;

		VkDescriptorPool m_DescriptorPool;
		std::vector<VkDescriptorSet> m_DescriptorSets;

		VkImage m_TextureImage;
		VkDeviceMemory m_TextureImageMemory;
	};
}