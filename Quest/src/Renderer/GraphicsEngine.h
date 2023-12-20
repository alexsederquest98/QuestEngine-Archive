#pragma once

#include "Core/Base.h"

#include "IDeviceContext.h"
#include "IRenderDevice.h"
#include "ISwapChain.h"

namespace Quest
{
	class GraphicsEngine
	{
	public:
		GraphicsEngine();
		~GraphicsEngine();

		RefPtr<IDeviceContext> GetContext();
		RefPtr<IDeviceContext> GetContext() const;
		RefPtr<IRenderDevice> GetRenderDevice();
		RefPtr<IRenderDevice> GetRenderDevice() const;
		RefPtr<ISwapChain> GetSwapChain();
		RefPtr<ISwapChain> GetSwapChain() const;

	private:
		RefPtr<IDeviceContext> m_Context;
		RefPtr<IRenderDevice> m_RenderDevice;
		RefPtr<ISwapChain> m_SwapChain;
	};
}