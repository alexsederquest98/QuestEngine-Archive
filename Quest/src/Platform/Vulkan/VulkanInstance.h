#pragma once

#include <vector>
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

		VkInstance& GetRaw();

	private:
		std::vector<const char*> GetRequiredExtensions();
		bool CheckValidationLayerSupport();

	private:
		VkInstance m_Instance;
	};
}