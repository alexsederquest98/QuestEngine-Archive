#pragma once
#include "Base.h"
#include "Events/Event.h"

#include <string>

namespace Quest
{
	// Specification struct for creating a new window
	struct WindowSpecification
	{
		std::string Title;
		uint32 Width;
		uint32 Height;

		WindowSpecification(const std::string title = "Quest Engine",
			uint32 width = 1920,
			uint32 height = 1080)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	// Interface for a window class
	class Window
	{
	public:
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;
		virtual std::string GetTitle() const = 0;
		virtual uint32 GetWidth() const = 0;
		virtual uint32 GetHeight() const = 0;
		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual void SetTitle(std::string_view title) = 0;
		virtual bool IsVSync() const = 0;
		virtual void* GetNativeWindow() const = 0; // Be sure to cast this to the proper native window in the caller function
		virtual float GetTime() const = 0; // This is not a great solution, but it's a simple way to get the glfw time for now

		static Scope<Window> Create(const WindowSpecification& spec = WindowSpecification());
	};
}