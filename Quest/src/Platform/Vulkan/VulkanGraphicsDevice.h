#pragma once
#include "Core/Base.h"
#include "Renderer/GraphicsDevice.h"

namespace Quest
{
	class VulkanGraphicsDevice : public GraphicsDevice
	{
	public:
		VulkanGraphicsDevice(const GraphicsDeviceSpecification& spec);
	};
}