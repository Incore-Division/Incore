#pragma once

#include "Core.h"

namespace Incore
{
	namespace Core
	{
		struct WindowProperties
		{
			const char* m_title;
			unsigned int m_width;
			unsigned int m_height;
			bool m_vsync;

			/* Constructor */
			WindowProperties(const char* title = "Incore", unsigned int width = 1280, unsigned int height = 720, bool vsync = true)
				: m_title(title), m_width(width), m_height(height), m_vsync(vsync) {}
		};

		class Window
		{
		public:

			/* Creates an window and returns a smart pointer for it */
			static Scope<Window> Create(WindowProperties& props = WindowProperties());

			/* Virtual Destructor */
			~Window() = default;

			/* Window main loop */
			virtual void OnUpdate() = 0;

			/* Returns the window itself */
			virtual void* GetNativeWindow() = 0;

		public:

			/* Returns the current window's title */
			virtual const char* GetTitle() const = 0;

			/* Sets a new window title */
			virtual void SetTitle(const char* title) = 0;

			/* Returns the current window's width */
			virtual unsigned int GetWidth() const = 0;

			/* Sets a new window width */
			virtual void SetWidth(unsigned int width) = 0;

			/* Returns the current window's height */
			virtual unsigned int GetHeight() const = 0;

			/* Sets a new window height */
			virtual void SetHeight(unsigned int height) = 0;

			/* Returns the current window's vsync status */
			virtual bool GetVsync() const = 0;

			/* Set's a new window vsync status */
			virtual void SetVsync(bool status) = 0;
		};
	}
}