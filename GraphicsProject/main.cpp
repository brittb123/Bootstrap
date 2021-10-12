#include "Engine.h"
#include "DragonWorld.h"

int main() {
	Engine* engine = new Engine(1280, 720, "Graphics");

	DragonWorld* world = new DragonWorld();

	engine->setActiveWorld(world);

	int exitCode = engine->run();

	delete world;
	delete engine;

	return exitCode;
}