#pragma once

#include "Core.h"
#include "Window.h"

namespace Incore
{
	namespace Core
	{
		class Application
		{
		public:

			/* Constructor */
			Application(int argc, char* argv[]);

			/* Destructor */
			~Application();

			/* Runs the application */
			void Run();

			/* Reads and set startup params */
			void ResolveParams(int argc, char* argv[]);

		public:

			/* Returns the application itself */
			inline static const Application& GetApplication() { return *s_application; }

			/* Returns the current operating system */
			inline static const OperatingSystem& GetOperatingSystem() { return s_operatingsystem; }

			/* Returns the current input system */
			inline static const InputSystem& GetInputSystem() { return s_inputsystem; }

			/* Returns the current renderer api */
			inline static const RendererApi& GetRendererApi() { return s_rendererapi; }

		private:

			Scope<Window> m_window;
			static Application* s_application;
			static OperatingSystem s_operatingsystem;
			static InputSystem s_inputsystem;
			static RendererApi s_rendererapi;

		};
	}
}