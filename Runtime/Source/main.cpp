#include <incore.h>

int main(int argc, char* argv[])
{
	Incore::Logger::Init();

	Incore::Application* app = new Incore::Application();
	app->ResolveParams(argc, argv);
	app->Run();

	delete app;

	return 0;
}