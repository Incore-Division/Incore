#include "ipch.h"
#include "Window.h"

namespace Incore
{
	namespace Platform
	{
		namespace Desktop
		{
			void ErrorCallback(int code, const char* message)
			{
				INCORE_CRITICAL("{0}:{1}", code, message);
			}

			Window::Window(const Core::WindowProperties& props) : m_props(props), m_window(nullptr)
			{
				bool glfw = glfwInit();
				INCORE_ASSERT(glfw, "GLFW was not successfully initialized");

				glfwSetErrorCallback(ErrorCallback);

				glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
				glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Vulkan resizes window in another way

				m_window = glfwCreateWindow(m_props.m_width, m_props.m_height, m_props.m_title, nullptr, nullptr);

				INCORE_ASSERT(m_window, "Window is a nullptr");
			}

			Window::~Window()
			{
				glfwDestroyWindow(m_window);
				glfwTerminate();
			}

			void Window::OnUpdate()
			{
				glfwPollEvents();
			}

			bool Window::ShouldClose()
			{
				return glfwWindowShouldClose(m_window);
			}

			void* Window::GetNativeWindow()
			{
				return m_window;
			}

			const char* Window::GetTitle() const
			{
				return m_props.m_title;
			}

			void Window::SetTitle(const char* title)
			{
				m_props.m_title = title;
				glfwSetWindowTitle(m_window, title);
			}

			unsigned int Window::GetWidth() const
			{
				return m_props.m_width;
			}

			void Window::SetWidth(unsigned int width)
			{
				m_props.m_width = width;
			}

			unsigned int Window::GetHeight() const
			{
				return m_props.m_height;
			}

			void Window::SetHeight(unsigned int height)
			{
				m_props.m_height = height;
			}

			bool Window::GetVsync() const
			{
				return m_props.m_vsync;
			}

			void Window::SetVsync(bool status)
			{
				m_props.m_vsync = status;
			}
		}
	}
}