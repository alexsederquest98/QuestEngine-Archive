#pragma once
#include "Core/Base.h"

#include <memory>

// Services to locate
#include "Core/Application.h"
#include "Core/Window.h"

#include "Renderer/IDeviceContext.h"
#include "Renderer/ISwapChain.h"
#include "Renderer/IRenderDevice.h"

namespace Quest
{
	// Static class of global services for easy retrieval
	class ServiceLocator
	{
	public:
		ServiceLocator() = delete;

		// Application
		static void RegisterApplication(Application* app);
		static Application* GetApplication();

		// Window
		static void RegisterWindow(Window* window);
		static Window* GetWindow();

		// IDeviceContext
		static void RegisterDeviceContext(IDeviceContext* context);
		static IDeviceContext* GetDeviceContext();

		// ISwapChain
		static void RegisterSwapChain(ISwapChain* swapchain);
		static ISwapChain* GetSwapChain();

		// IRenderDevice
		static void RegisterRenderDevice(IRenderDevice* device);
		static IRenderDevice* GetRenderDevice();
	private:
		static Application* m_ApplicationService;
		static Window* m_WindowService;

		// Temporary for now probably
		static IDeviceContext* m_DeviceContextService;
		static ISwapChain* m_SwapChainService;
		static IRenderDevice* m_RenderDeviceService;
	};
}