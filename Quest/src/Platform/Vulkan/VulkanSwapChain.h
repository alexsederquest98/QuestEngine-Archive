#pragma once

#include "Core/Base.h"

#include "Core/Window.h"
#include "VulkanDevice.h"

#include <vulkan/vulkan.h>

struct GLFWwindow;

namespace Quest
{
	struct SwapChainSupportDetails
	{
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	class VulkanSwapChain
	{
	public:
		VulkanSwapChain();
		~VulkanSwapChain();

		void Init(VkInstance instance, const RefPtr<VulkanDevice>& device, const RefPtr<Window>& window);
		void Shutdown();
		void InitSurface();
		void Create(uint32_t width, uint32_t height, bool vsync);
		void Destroy();

		void OnResize(uint32_t width, uint32_t height);
		
		void PresentImage();
	private:
		SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);
		VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

		void CreateImageViews();
		void CreateDepthResources();
		void CreateFramebuffers();

		VkImageView CreateImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags);
		VkFormat FindDepthFormat();
		VkFormat FindSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
		void CreateImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
		uint32_t FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
		void TransitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);
	private:
		VkInstance m_Instance = nullptr;
		RefPtr<VulkanDevice> m_Device;
		RefPtr<Window> m_Window;
		bool m_VSync = false;

		VkSwapchainKHR m_SwapChain = nullptr;
		uint32_t m_ImageCount = 0;

		std::vector<VkImage> m_SwapChainImages;
		VkFormat m_SwapChainImageFormat;
		VkExtent2D m_SwapChainExtent;

		std::vector<VkImageView> m_SwapChainImageViews;
		std::vector<VkFramebuffer> m_SwapChainFramebuffers;

		VkImage m_DepthImage;
		VkDeviceMemory m_DepthImageMemory;
		VkImageView m_DepthImageView;

		VkSurfaceKHR m_Surface = nullptr;

		friend class VulkanRenderDevice;
	};
}