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

	class VulkanGraphicsDevice : public GraphicsDevice
	{
	public:
		VulkanGraphicsDevice(const GraphicsDeviceSpecification& spec);
		~VulkanGraphicsDevice();
	private:
		void Init(); // Vulkan init function, initialize all the objects required for Vulkan to function
		void Shutdown(); // clean up function

		// Vulkan object creation functions
		void CreateInstance();
		void SetupDebugMessenger();
		void CreateSurface();
		void PickPhysicalDevice();
		void CreateLogicalDevice();

		
		// Instance helper
		std::vector<const char*> GetRequiredExtensions();

		// Physical Device helpers
		bool IsDeviceSuitable(VkPhysicalDevice device);
		QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);

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
	};
}