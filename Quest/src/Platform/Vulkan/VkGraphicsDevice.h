#pragma once
#include "Core/Base.h"
#include "Renderer/GraphicsDevice.h"

namespace Quest
{
	class VkGraphicsDevice : public GraphicsDevice
	{
	public:
		VkGraphicsDevice(const GraphicsDeviceSpecification& spec);
	};
}