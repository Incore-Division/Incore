#include "ipch.h"
#include "Window.h"

namespace Incore
{
	namespace Platform
	{
		namespace Desktop
		{
			Window::Window(const Core::WindowProperties& props) : m_props(props), m_window(nullptr)
			{

			}

			Window::~Window()
			{

			}

			void Window::OnUpdate()
			{

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
				glfwSetWindowSize(m_window, width, m_props.m_height);
			}

			unsigned int Window::GetHeight() const
			{
				return m_props.m_height;
			}

			void Window::SetHeight(unsigned int height)
			{
				m_props.m_height = height;
				glfwSetWindowSize(m_window, m_props.m_width, height);
			}

			bool Window::GetVsync() const
			{
				return m_props.m_vsync;
			}

			void Window::SetVsync(bool status)
			{
				// Vertical Syncronization will be done by vulkan
			}
		}
	}
}