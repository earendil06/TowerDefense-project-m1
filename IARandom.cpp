#include "IARandom.h"
#include <vector>
#include "EnvironmentUtils.h"
#include "World.h"
#include <functional>


IARandom::IARandom() {}


IARandom::~IARandom()
{
}

int IARandom::randint(int min, int max) {
	return min + (rand() % static_cast<int>(max - min + 1));
}

void IARandom::goForward() {
	if (!getPlace()->isArrival()) {
		bool byPath = false;
		std::vector<std::pair<int, int>> coordsToGo(EnvironmentUtils::possiblesCoordsToGo(World::getMatrix(), World::getMatrix()->couplesArround(getPlace()->getI(), getPlace()->getJ())));
		WayFrame* next;
		int nbChoices = coordsToGo.size();
		bool pioche = false;
		for (int i = 0; i < nbChoices; i++) {
			std::pair<int, int> couple = coordsToGo.at(i);
			WayFrame* place = static_cast<WayFrame*>(World::getMatrix()->getValue(couple.first, couple.second));
			if (placesVisited.find(place) == placesVisited.end()) {
				pioche = true;
				break;
			}
		}
		if (pioche) {
			do {
				int rand = randint(0, nbChoices - 1);
				std::pair<int, int> couple = coordsToGo.at(rand);
				next = static_cast<WayFrame*>(World::getMatrix()->getValue(couple.first, couple.second));
			} while (placesVisited.find(next) != placesVisited.end());
		}
		else {
			next = World::getGraph()->path(getPlace(), EnvironmentUtils::getArrival(World::getMatrix())).at(1);
			byPath = true;
			placesVisited.insert(getPlace());
		}
		if (!byPath) placesVisited.insert(getPlace());
		setPlace(next);
	}
}
