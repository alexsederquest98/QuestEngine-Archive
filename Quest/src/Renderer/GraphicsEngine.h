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

		inline RefPtr<IDeviceContext> GetContext();
		inline RefPtr<IDeviceContext> GetContext() const;
		inline RefPtr<IRenderDevice> GetRenderDevice();
		inline RefPtr<IRenderDevice> GetRenderDevice() const;
		inline RefPtr<ISwapChain> GetSwapChain();
		inline RefPtr<ISwapChain> GetSwapChain() const;

	private:
		RefPtr<IDeviceContext> m_Context;
		RefPtr<IRenderDevice> m_RenderDevice;
		RefPtr<ISwapChain> m_SwapChain;
	};
}