#include "qepch.h"
#include "IRenderDevice.h"
#include "IDeviceContext.h"

//#include "Platform/OpenGL/OpenGLDeviceContext.h"
#include "Platform/Vulkan/VulkanDeviceContext.h"

namespace Quest
{
	Ref<IDeviceContext> IDeviceContext::Create(void* window)
	{
		switch (IRenderDevice::GetAPI())
		{
		case IRenderDevice::API::None:		QE_CORE_ASSERT_MSG(false, "IRenderDevice::API::None is not supported"); return nullptr;
		//case IRenderDevice::API::OpenGL:	return CreateRef<OpenGLDeviceContext>(static_cast<GLFWwindow*>(window));
		case IRenderDevice::API::Vulkan:	return CreateRef<VulkanDeviceContext>(static_cast<GLFWwindow*>(window));
		}

		QE_CORE_ASSERT_MSG(false, "Invalid API");
		return nullptr;
	}
}