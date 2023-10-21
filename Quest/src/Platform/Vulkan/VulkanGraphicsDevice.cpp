#include "qepch.h"
#include "Core/Base.h"
#include "VulkanGraphicsDevice.h"

namespace Quest
{
	VulkanGraphicsDevice::VulkanGraphicsDevice(const GraphicsDeviceSpecification& spec)
	{
		// Init Vulkan objects
		Init();
	}

	VulkanGraphicsDevice::~VulkanGraphicsDevice()
	{
		// Release all Vulkan object memory; probably will update with RAII or smart pointers later
		Shutdown();
	}

	void VulkanGraphicsDevice::Init()
	{
		CreateInstance();
	}

	void VulkanGraphicsDevice::Shutdown()
	{
		m_Instance.Shutdown();
	}

	void VulkanGraphicsDevice::CreateInstance()
	{
		m_Instance.Init();
	}
}