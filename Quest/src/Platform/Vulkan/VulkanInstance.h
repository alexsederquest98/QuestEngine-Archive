#pragma once
#include <vulkan/vulkan.h>

namespace Quest
{
	class VulkanInstance
	{
	public:
		VulkanInstance();
		~VulkanInstance();

		void Init();
		void Shutdown();

		VkInstance GetRaw();
	private:
		VkInstance m_Instance;
	};
}