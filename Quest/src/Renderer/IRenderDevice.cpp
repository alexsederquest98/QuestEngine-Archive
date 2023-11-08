#include "qepch.h"
#include "IRenderDevice.h"

// Platform implementations of RenderDevice(s)
//#include "Platform/Vulkan/VulkanRenderDevice.h"
#include "Platform/OpenGL/OpenGLRenderDevice.h"
#include "Platform/Vulkan/VulkanGraphicsDevice.h"

namespace Quest
{
	IRenderDevice::API IRenderDevice::s_API = IRenderDevice::API::OpenGL;

	Ref<IRenderDevice> IRenderDevice::Create(const RenderDeviceSpecification& spec)
	{
		switch (s_API)
		{
		case IRenderDevice::API::None:		QE_CORE_ASSERT_MSG(false, "IRenderDevice::API::None is not supported"); return nullptr;
		case IRenderDevice::API::OpenGL:	return CreateRef<OpenGLRenderDevice>(spec);
		case IRenderDevice::API::Vulkan:	QE_CORE_ASSERT_MSG(false, "Vulkan is not fully supported now"); return nullptr;
		}
		
		QE_CORE_ASSERT_MSG(false, "Invalid API");
		return nullptr;
	}
}