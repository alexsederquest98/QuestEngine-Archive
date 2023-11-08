#include "qepch.h"
#include "IRenderDevice.h"

// Platform implementations of RenderDevice(s)
//#include "Platform/Vulkan/VulkanRenderDevice.h"
#include "Platform/Vulkan/VulkanGraphicsDevice.h"

namespace Quest
{
	Scope<IRenderDevice> IRenderDevice::Create(const RenderDeviceSpecification& spec)
	{
		return CreateScope<VulkanGraphicsDevice>(spec);
	}
}