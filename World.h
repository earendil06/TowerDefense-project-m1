#pragma once
#include <vector>
#include "Drawable.h"
#include "Matrix.h"
#include "AbstractFrame.h"
#include "Actionable.h"
#include "AbstractMonster.h"
#include "Graph.h"
#include "Commande.h"
#include <queue>
#include "AbstractTower.h"
#include "Bullet.h"

class World {

private:
	std::vector<Drawable*> drawables;
	std::vector<Actionable*> actionables;

	Matrix<AbstractFrame*>* matrix;
	Graph* graph;
	std::queue<Commande*>* chronologie;

	std::vector<AbstractMonster*> monsters;
	std::vector<AbstractTower*> towers;
	std::vector<Bullet*> bullets;;

	World() : matrix(nullptr), graph(nullptr), chronologie(nullptr) {};
	~World() {
		delete matrix, graph, chronologie;
	};

public:
	static World* instance();
	static std::vector<Drawable*>* getDrawables();
	static std::vector<Actionable*>* getActionables();
	static Matrix<AbstractFrame*>* getMatrix();
	static std::queue<Commande*>* getChronologie();
	static Graph* getGraph();
	static void addDrawable(Drawable*);
	static void configureMatrix(Matrix<AbstractFrame*>*);
	static void configureChronologie(std::queue<Commande*>*);
	static std::vector<AbstractMonster*>* getMonsters();
	static std::vector<AbstractTower*>* getTowers();
	static std::vector<Bullet*>* getBullets();
};

inline World* World::instance() {
	static World* m_instance = new World();
	return m_instance;
}

inline std::vector<Drawable*>* World::getDrawables() {
	instance()->drawables.clear();
	for (int i = 0; i < getMatrix()->getNbLines(); i++) {
		for (int j = 0; j < getMatrix()->getNbColumns(); j++) {
			instance()->drawables.push_back(getMatrix()->getValue(i, j));
		}
	}
	for(AbstractMonster* monster : instance()->monsters) {
		instance()->drawables.push_back(monster);
	}
	for (AbstractTower* tower : instance()->towers) {
		instance()->drawables.push_back(tower);
	}
	for (Bullet* bullet : instance()->bullets) {
		instance()->drawables.push_back(bullet);
	}
	return &(instance()->drawables);
}

inline std::vector<Actionable*>* World::getActionables() {
	instance()->actionables.clear();
	for (AbstractMonster* monster : instance()->monsters) {
		instance()->actionables.push_back(monster);
	}
	for (AbstractTower* tower : instance()->towers) {
		instance()->actionables.push_back(tower);
	}
	for (Bullet* bullet : instance()->bullets) {
		instance()->actionables.push_back(bullet);
	}
	return &(instance()->actionables);
}

inline Matrix<AbstractFrame*>* World::getMatrix() {
	return instance()->matrix;
}

inline std::queue<Commande*>* World::getChronologie() {
	return instance()->chronologie;
}

inline Graph* World::getGraph() {
	return instance()->graph;
}

inline void World::addDrawable(Drawable* dr) {
	instance()->getDrawables()->push_back(dr);
}

inline void World::configureMatrix(Matrix<AbstractFrame*>* m) {
	instance()->matrix = m;
	instance()->graph = new Graph(m);
}

inline void World::configureChronologie(std::queue<Commande*>* queue) {
	instance()->chronologie = queue;
}

inline std::vector<AbstractMonster*>* World::getMonsters() {
	return &(instance()->monsters);
}

inline std::vector<AbstractTower*>* World::getTowers() {
	return &(instance()->towers);
}

inline std::vector<Bullet*>* World::getBullets() {
	return &(instance()->bullets);
}
