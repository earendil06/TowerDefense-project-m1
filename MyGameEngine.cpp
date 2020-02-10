
#include "MyGameEngine.h"
#include "World.h"


void MyGameEngine::idle() {
	ticks++;

	Commande* commande = World::getChronologie()->front();
	if (commande != nullptr && commande->getTick() == ticks) {
		commande->execute();
		World::getChronologie()->pop();
	}

	for (int i = 0; i < World::getActionables()->size(); i++) {
		World::getActionables()->at(i)->tick();
	}
}

int MyGameEngine::getNbTicks() const {
	return ticks;
}
