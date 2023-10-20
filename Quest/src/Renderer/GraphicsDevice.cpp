#include "qepch.h"
#include "GraphicsDevice.h"

// Platform implementations of GraphicsDevice(s)
#include "Platform/Vulkan/VkGraphicsDevice.h"

namespace Quest
{
	Scope<GraphicsDevice> GraphicsDevice::Create(const GraphicsDeviceSpecification& spec)
	{
		return CreateScope<VkGraphicsDevice>(spec);
	}
}