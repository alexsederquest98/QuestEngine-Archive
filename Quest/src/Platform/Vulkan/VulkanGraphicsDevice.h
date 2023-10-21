#pragma once
#include "Core/Base.h"
#include "Renderer/GraphicsDevice.h"

#include "VulkanInstance.h"

namespace Quest
{
	class VulkanGraphicsDevice : public GraphicsDevice
	{
	public:
		VulkanGraphicsDevice(const GraphicsDeviceSpecification& spec);
		~VulkanGraphicsDevice();
	private:
		void Init(); // Vulkan init function, initialize all the objects required for Vulkan to function
		void Shutdown(); // clean up function

		void CreateInstance();

	private:
		VulkanInstance m_Instance;
	};
}