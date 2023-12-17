#include "qepch.h"

#include "ServiceLocator.h"

namespace Quest
{
	// Initializations
	Application* ServiceLocator::m_ApplicationService = nullptr;
	Window* ServiceLocator::m_WindowService = nullptr;

	IDeviceContext* ServiceLocator::m_DeviceContextService = nullptr;
	ISwapChain* ServiceLocator::m_SwapChainService = nullptr;
	IRenderDevice* ServiceLocator::m_RenderDeviceService = nullptr;


	void ServiceLocator::RegisterApplication(Application* app)
	{
		m_ApplicationService = app;
	}

	Application* ServiceLocator::GetApplication()
	{
		return m_ApplicationService;
	}

	void ServiceLocator::RegisterWindow(Window* window)
	{
		m_WindowService = window;
	}

	Window* ServiceLocator::GetWindow()
	{
		return m_WindowService;
	}

	void ServiceLocator::RegisterDeviceContext(IDeviceContext* context)
	{
		m_DeviceContextService = context;
	}

	IDeviceContext* ServiceLocator::GetDeviceContext()
	{
		return m_DeviceContextService;
	}

	void ServiceLocator::RegisterSwapChain(ISwapChain* swapchain)
	{
		m_SwapChainService = swapchain;
	}

	ISwapChain* ServiceLocator::GetSwapChain()
	{
		return m_SwapChainService;
	}

	void ServiceLocator::RegisterRenderDevice(IRenderDevice* device)
	{
		m_RenderDeviceService = device;
	}

	IRenderDevice* ServiceLocator::GetRenderDevice()
	{
		return m_RenderDeviceService;
	}

}