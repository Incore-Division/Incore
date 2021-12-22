#pragma once

#include "Core/Window.h"

// Only Vulkan support for now
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Incore
{
	namespace Platform
	{
		namespace Desktop
		{
			class Window : public Core::Window
			{
			public:

				/* Constructor */
				Window(const Core::WindowProperties& props);

				/* Destructor */
				~Window();

				/* Window main loop */
				virtual void OnUpdate() override;

				/* Returns if the window should be shut down */
				virtual bool ShouldClose() override;

				/* Returns the window itself */
				virtual void* GetNativeWindow() override;

			public:

				/* Returns the current window's title */
				virtual const char* GetTitle() const override;

				/* Sets a new window title */
				virtual void SetTitle(const char* title) override;

				/* Returns the current window's width */
				virtual unsigned int GetWidth() const override;

				/* Sets a new window width */
				virtual void SetWidth(unsigned int width) override;

				/* Returns the current window's height */
				virtual unsigned int GetHeight() const override;

				/* Sets a new window height */
				virtual void SetHeight(unsigned int height) override;

				/* Returns the current window's vsync status */
				virtual bool GetVsync() const override;

				/* Set's a new window vsync status */
				virtual void SetVsync(bool status) override;

			private:

				Core::WindowProperties m_props;
				GLFWwindow* m_window;

			};
		}
	}
}