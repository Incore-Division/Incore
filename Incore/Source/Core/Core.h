#pragma once

#include <memory>

namespace Incore
{
	namespace Core
	{
		enum class OperatingSystem
		{
			Undefined = 0,
			Windows,
			Linux,
			Mac
		};

		/* Returns the operating system as a const char* */
		inline const char* ToConstChar(OperatingSystem os)
		{
			switch (os)
			{
			case OperatingSystem::Windows: return "Windows";
			case OperatingSystem::Linux: return "Linux";
			case OperatingSystem::Mac: return "Mac";
			}

			return "Unknown operating system";
		}

		enum class InputSystem
		{
			Undefined = 0,
			Desktop,
			Controller
		};

		/* Returns the input system as a const char* */
		inline const char* ToConstChar(InputSystem is)
		{
			switch (is)
			{
			case InputSystem::Desktop: return "Keyboard and Mouse";
			case InputSystem::Controller: return "Controller";
			}

			return "Unknown input system";
		}

		enum class RendererApi
		{
			Undefined = 0,
			Vulkan,
			OpenGL
		};

		/* Returns the renderer api as a const char* */
		inline const char* ToConstChar(RendererApi ra)
		{
			switch (ra)
			{
			case RendererApi::Vulkan: return "Vulkan";
			case RendererApi::OpenGL: return "OpenGL";
			}

			return "Unknown renderer api";
		}

		/* std::unique_ptr smart pointer */
		template<typename T>
		using Scope = std::unique_ptr<T>;
		template<typename T, typename ... Args>
		constexpr Scope<T> CreateScope(Args&& ... args)
		{
			return std::make_unique<T>(std::forward<Args>(args)...);
		}

		/* std::shared_ptr smart pointer */
		template<typename T>
		using Reference = std::shared_ptr<T>;
		template<typename T, typename ... Args>
		constexpr Reference<T> CreateReference(Args&& ... args)
		{
			return std::make_shared<T>(std::forward<Args>(args)...);
		}
	}
}