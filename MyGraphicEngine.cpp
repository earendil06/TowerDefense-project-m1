
#include "MyGraphicEngine.h"
#include "World.h"

void MyGraphicEngine::Draw() {
	for (int i = 0; i < World::getDrawables()->size(); i++) {
		World::getDrawables()->at(i)->draw();
	}
}

