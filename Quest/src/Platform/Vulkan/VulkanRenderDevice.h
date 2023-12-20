#pragma once

#include "Core/Base.h"
#include "Renderer/IRenderDevice.h"

#include "VulkanDevice.h"
#include "VulkanSwapChain.h"

#include <vulkan/vulkan.h>

#include <vector>

namespace Quest
{
	class VulkanRenderDevice : public IRenderDevice
	{
	public:
		VulkanRenderDevice(const RenderDeviceSpecification& spec);
		~VulkanRenderDevice();

		void Shutdown();

		void DrawFrame() override;
		void WaitForDeviceToFinishExecuting() override;
		void FramebufferResize(uint32_t width, uint32_t height) override { m_FramebufferResized = true; }

		static VkInstance GetInstance() { return s_Instance; }

		RefPtr<VulkanDevice> GetDevice() { return m_Device; }

		const bool GetEnabledValidation();
		const std::vector<const char*> GetValidationLayers();
	private:
		void CreateInstance();
		std::vector<const char*> GetRequiredExtensions();

		void SetupDebugMessenger();
	private:
		inline static VkInstance s_Instance;
		RefPtr<VulkanPhysicalDevice> m_PhysicalDevice;
		RefPtr<VulkanDevice> m_Device;
		RefPtr<VulkanSwapChain> m_SwapChain;

		VkDebugUtilsMessengerEXT m_DebugMessenger;

		bool m_FramebufferResized = false;


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