#pragma once
#include <vector>
#include "Matrix.h"
#include "WayFrame.h"
#include "AbstractMonster.h"
#include "TankMonster.h"
#include "IAFactory.h"
#include "World.h"

class EnvironmentUtils
{
public:
	static std::vector<std::pair<int, int>> possiblesCoordsToGo(Matrix<AbstractFrame*>*, std::vector<std::pair<int, int>>);
	static WayFrame* getDeparture(Matrix<AbstractFrame*>*);
	static WayFrame* getArrival(Matrix<AbstractFrame*>*);
	static void generateMonster(char);
	static void killMonster(AbstractMonster*);

private:
	EnvironmentUtils() {}
	~EnvironmentUtils() {}
	
};

inline std::vector<std::pair<int, int>> EnvironmentUtils::possiblesCoordsToGo(Matrix<AbstractFrame*>* matrix, std::vector<std::pair<int, int>> couples) {
	std::vector<std::pair<int, int>> result;
	for(int idx = 0; idx < couples.size(); idx++){
		int i = couples.at(idx).first;
		int j = couples.at(idx).second;
		AbstractFrame* frame = matrix->getValue(i, j);
		if (dynamic_cast<WayFrame*>(frame) != nullptr) {
			std::pair<int, int> couple(i, j);
			result.push_back(couple);
		}
	}
	return result;
}

inline WayFrame* EnvironmentUtils::getDeparture(Matrix<AbstractFrame*>* matrix) {
	for (int i = 0; i < matrix->getNbLines(); i++) {
		for (int j = 0; j < matrix->getNbColumns(); j++) {
			AbstractFrame* frame = matrix->getValue(i, j);
			if (dynamic_cast<WayFrame*>(frame) != nullptr && dynamic_cast<WayFrame*>(frame)->isDeparture()) {
				return static_cast<WayFrame*>(frame);
			}
		}
	}
	return nullptr;
}

inline WayFrame* EnvironmentUtils::getArrival(Matrix<AbstractFrame*>* matrix) {
	for (int i = 0; i < matrix->getNbLines(); i++) {
		for (int j = 0; j < matrix->getNbColumns(); j++) {
			AbstractFrame* frame = matrix->getValue(i, j);
			if (dynamic_cast<WayFrame*>(frame) != nullptr && dynamic_cast<WayFrame*>(frame)->isArrival()) {
				return static_cast<WayFrame*>(frame);
			}
		}
	}
	return nullptr;
}

inline void EnvironmentUtils::generateMonster(char type) {
	AbstractMonster* monster = new TankMonster(type);
	World::getMonsters()->push_back(monster);
}

inline void EnvironmentUtils::killMonster(AbstractMonster* abstract_monster) {
	World::getMonsters()->erase(std::remove(World::getMonsters()->begin(), World::getMonsters()->end(), abstract_monster), World::getMonsters()->end());
}
