#include "qepch.h"
#include "Core/Base.h"
#include "VulkanGraphicsDevice.h"

#include <vulkan/vulkan.h>

namespace Quest
{
	VulkanGraphicsDevice::VulkanGraphicsDevice(const GraphicsDeviceSpecification& spec)
	{
		uint32 extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
		QE_CORE_INFO("Vulkan - {0} extensions supported", extensionCount);

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