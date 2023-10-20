#pragma once
#include "Core/Base.h"

namespace Quest
{
	class GraphicsDevice
	{
	public:
		struct GraphicsDeviceSpecification
		{

		};

		static Scope<GraphicsDevice> Create(const GraphicsDeviceSpecification& spec = GraphicsDeviceSpecification());
	};
}