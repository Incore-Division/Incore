#pragma once

#include "Core.h"

namespace Incore
{
	class Application
	{
	public:

		/* Constructor */
		Application();

		/* Destructor */
		~Application();

		/* Runs the application */
		void Run();

	public:

		/* Returns the application itself */
		inline static const Application& GetApplication() { return *s_application; }

		/* Returns the current operating system */
		inline static const OperatingSystem& GetOperatingSystem() { return s_operatingsystem; }

		/* Returns the current input system */
		inline static const InputSystem& GetInputSystem() { return s_inputsystem; }

		/* Returns the current renderer api */
		inline static const RendererApi& GetRendererApi() { return s_rendererapi; }
 
	protected:

		/* Reads and set startup params */
		void ResolveParams(int argc, char* argv[]);

	private:

		static Application* s_application;
		static OperatingSystem s_operatingsystem;
		static InputSystem s_inputsystem;
		static RendererApi s_rendererapi;

	};
}