#include "qepch.h"

#include "GraphicsEngine.h"

namespace Quest
{
	GraphicsEngine::GraphicsEngine()
	{
	}

	GraphicsEngine::~GraphicsEngine()
	{
	}

	RefPtr<IDeviceContext> GraphicsEngine::GetContext()
	{
		return m_Context;
	}

	RefPtr<IDeviceContext> GraphicsEngine::GetContext() const
	{
		return m_Context;
	}

	RefPtr<IRenderDevice> GraphicsEngine::GetRenderDevice()
	{
		return m_RenderDevice;
	}

	RefPtr<IRenderDevice> GraphicsEngine::GetRenderDevice() const
	{
		return m_RenderDevice;
	}

	RefPtr<ISwapChain> GraphicsEngine::GetSwapChain()
	{
		return m_SwapChain;
	}

	RefPtr<ISwapChain> GraphicsEngine::GetSwapChain() const
	{
		return m_SwapChain;
	}

}