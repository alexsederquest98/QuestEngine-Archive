#include "qepch.h"
#include "InputManager.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Quest
{
	bool InputManager::IsKeyPressed(const KeyCode key)
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto keyState = glfwGetKey(window, static_cast<int32_t>(key));
		return keyState == GLFW_PRESS;
	}

	bool InputManager::IsMouseButtonPressed(const MouseCode button)
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto mouseState = glfwGetMouseButton(window, static_cast<int32_t>(button));
		return mouseState == GLFW_PRESS;
	}

	glm::vec2 InputManager::GetMousePosition()
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return { (float)xpos, (float)ypos };
	}

	float InputManager::GetMouseX()
	{
		return GetMousePosition().x;
	}

	float InputManager::GetMouseY()
	{
		return GetMousePosition().y;
	}
}