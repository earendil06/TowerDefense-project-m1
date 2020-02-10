#include "Bullet.h"
#include <GraphicPrimitives.h>
#include "World.h"


Bullet::Bullet(): x(0), y(0), target(nullptr), speed(0) {}
Bullet::Bullet(float _x, float _y, const AbstractTower* _t, AbstractMonster* _m): x(_x), y(_y), target(_m), source(_t), speed(0.01) { }

Bullet::~Bullet()
{
}

void Bullet::draw() {
	int ratio = 10;
	GraphicPrimitives::drawFillRect2D(x, y, World::getMatrix()->getValue(0, 0)->getWidth() / ratio, World::getMatrix()->getValue(0, 0)->getHeight() / ratio, 1.0, 1.0, 1.0);
}
void Bullet::act() {
	float tX = target->getX() - x;
	float tY = target->getY() - y;
	float dist = sqrt(pow(tX, 2) + pow(tY, 2));
	if (dist < 0.01 ) {
		target->setPV(0);
		World::getBullets()->erase(std::remove(World::getBullets()->begin(), World::getBullets()->end(), this), World::getBullets()->end());
	}
	else {
		float theta = 2 * atan(tY / (tX + dist));
		x += speed * cos(theta);
		y += speed * sin(theta);
	}
	
}
