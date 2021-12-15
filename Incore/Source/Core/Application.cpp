#include "ipch.h"
#include "Application.h"

namespace Incore
{
	/* Declaration of static variables */
	Application* Application::s_application = nullptr;
	OperatingSystem Application::s_operatingsystem = OperatingSystem::Undefined;
	InputSystem Application::s_inputsystem = InputSystem::Undefined;
	RendererApi Application::s_rendererapi = RendererApi::Undefined;

	Application::Application()
	{
		s_application = this;
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{

	}

	void Application::ResolveParams(int argc, char* argv[])
	{
		// detects the operating system
		#if defined (_WIN32) || defined(_WIN64)
		s_operatingsystem = OperatingSystem::Windows;
		#elif defined(__APPLE__)
		s_operatingsystem = OperatingSystem::Macosx;
		#elif defined(__linux__)
		s_operatingsystem = OperatingSystem::Linux;
		#else
		s_operatingsystem = OperatingSystem::Undefined;
		#endif

		// analyzes the params
		for (int i = 0; i < argc; i += 2)
		{
			if (argv[i] == "-api" && argv[i + 1] == "opengl") s_rendererapi = RendererApi::OpenGL;
			if (argv[i] == "-api" && argv[i + 1] == "vulkan") s_rendererapi = RendererApi::Vulkan;

			if (argv[i] == "-input" && argv[i + 1] == "desktop") s_inputsystem = InputSystem::Desktop;
			if (argv[i] == "-input" && argv[i + 1] == "controller") s_inputsystem = InputSystem::Controller;
		}

		// auto-define to vulkan and keyboard+mouse if 
		if (s_rendererapi == RendererApi::Undefined) s_rendererapi = RendererApi::Vulkan;
		if (s_inputsystem == InputSystem::Undefined) s_inputsystem = InputSystem::Desktop;
	}
}