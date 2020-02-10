#include "AbstractTower.h"
#include <GraphicPrimitives.h>
#include "World.h"


AbstractTower::AbstractTower(): waitShooter(0), distanceArea(0), place(nullptr), r(0), g(0), b(0) {}

AbstractTower::AbstractTower(LandFrame* frame): r(0), g(0), b(0), level(0) {
	place = frame;
	distanceArea = 2 * frame->getWidth();
	waitShooter = 100;
}

AbstractTower::~AbstractTower()
{
	delete place;
}

void AbstractTower::shot(AbstractMonster* target) const {
	Bullet* bullet = new Bullet(place->getAncrageX() + place->getWidth() / 2, place->getAncrageY() + place->getHeight() / 2, this, target);
	World::getBullets()->push_back(bullet);
}

void AbstractTower::act() {
	AbstractMonster* target = nullptr;
	float distTarget = FLT_MAX;
	for (AbstractMonster* monster : *World::getMonsters()) {
		float distance = distanceTo(monster);
		if (distance < distanceArea && distance < distTarget) {
			distTarget = distance;
			target = monster;
		}
	}
	if (target != nullptr) {
		if (currentWait % waitShooter == 0) {
			currentWait = 0;
			shot(target);
		}
		currentWait++;
	}
	else {
		currentWait = 0;
	}
}

void AbstractTower::draw() {
	double ratio = 1.5;
	double div = 2 * ratio;
	float plopX = (place->getWidth() / div) * (ratio -1);
	float plopY = (place->getHeight() / div) * (ratio -1);
	GraphicPrimitives::drawFillRect2D(place->getAncrageX() + plopX, place->getAncrageY() + plopY, (place->getWidth() * 2) / div, (place->getHeight() * 2) / div, r, g, b);
}

float AbstractTower::distanceTo(AbstractMonster* monster) const {
	float myX = place->getAncrageX() + place->getWidth() / 2;
	float myY = place->getAncrageY() + place->getHeight() / 2;
	return sqrt(pow(monster->getX() - myX, 2) + pow(monster->getY() - myY, 2));
}
