#include <incore.h>

int main(int argc, char* argv[])
{
	Incore::Core::Logger::Init();

	Incore::Core::Application* app = new Incore::Core::Application(argc, argv);
	app->Run();

	delete app;

	return 0;
}