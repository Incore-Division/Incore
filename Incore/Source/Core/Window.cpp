#include "ipch.h"
#include "Window.h"
#include "Application.h"

#include "Platform/Desktop/Window.h"

namespace Incore
{
	namespace Core
	{
		Scope<Window> Window::Create(WindowProperties& props)
		{
			switch (Application::GetOperatingSystem())
			{
				case OperatingSystem::Windows: return CreateScope<Platform::Desktop::Window>(props);
				case OperatingSystem::Linux: return CreateScope<Platform::Desktop::Window>(props);
				case OperatingSystem::Mac: return CreateScope<Platform::Desktop::Window>(props);
			}

			INCORE_ASSERT(false, "Error, platform undefined when attempting to create a window");
			return nullptr;
		}
	}
}