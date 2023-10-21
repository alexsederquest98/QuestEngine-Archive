#pragma once
#include "Core/Base.h"
#include "Core/Window.h"

namespace Quest
{
	class GraphicsDevice
	{
	public:
		struct GraphicsDeviceSpecification
		{
			Ref<Window> window;
		};

		virtual ~GraphicsDevice() = default;

		static Scope<GraphicsDevice> Create(const GraphicsDeviceSpecification& spec);
	protected:
		Ref<Window> m_Window;
	};
}