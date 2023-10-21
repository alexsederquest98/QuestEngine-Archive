#pragma once
#include "Core/Base.h"
#include "Renderer/GraphicsDevice.h"

#include <vector>

#include <vulkan/vulkan.h>

namespace Quest
{
	class VulkanGraphicsDevice : public GraphicsDevice
	{
	public:
		VulkanGraphicsDevice(const GraphicsDeviceSpecification& spec);
		~VulkanGraphicsDevice();
	private:
		void Init(); // Vulkan init function, initialize all the objects required for Vulkan to function
		void Shutdown(); // clean up function

		void CreateInstance();
		void SetupDebugMessenger();

		
		// Instance helpers
		std::vector<const char*> GetRequiredExtensions();

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
	};
}