#include "qepch.h"
#include "Window.h"

// Platform specific window
#include "Platform/Windows/WindowsWindow.h"

namespace Quest
{
	// will need platform guards eventually
	// but since I will be using glfw for now, a WindowsWindow will still be platform-agnostic
	Ref<Window> Window::Create(const WindowSpecification& spec)
	{
		return CreateRef<WindowsWindow>(spec);
	}
}