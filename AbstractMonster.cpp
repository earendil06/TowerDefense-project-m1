#include "AbstractMonster.h"
#include <vector>
#include "World.h"
#include <GraphicPrimitives.h>
#include "IAFactory.h"
#include "MyGameEngine.h"
#include <float.h>
#include "EnvironmentUtils.h"


AbstractMonster::AbstractMonster(char c) : IA(IAFactory::fromType(c)), r(0), g(0), b(0), pv(1), slow(0.01),
                                           x(IA->getPlace()->getAncrageX() + IA->getPlace()->getWidth() / 2),
                                           y(IA->getPlace()->getAncrageY() + IA->getPlace()->getHeight() / 2), blockIA(false) { }


AbstractMonster::~AbstractMonster()
{
	delete IA;
}

void AbstractMonster::setPV(int nb) {
	pv = nb;
}

void AbstractMonster::setSlow(int newSlow) {
	slow = newSlow;
}

float AbstractMonster::getX() const {
	return x;
}

float AbstractMonster::getY() const {
	return y;
}

void AbstractMonster::draw() {
	double PI = acos(-1);
	int nb = 4;
	float amp = 0.5;
	std::vector<float> listeX;
	std::vector<float> listeY;
	for(double xx = 0; xx < 2 * PI; xx += (2 * PI) / nb) {
		float a = (cos(xx) / World::getMatrix()->getNbColumns()) * amp;
		float o = (sin(xx) / World::getMatrix()->getNbLines()) * amp;
		listeX.push_back(a + x);
		listeY.push_back(o + y);
	}

	GraphicPrimitives::drawFillPolygone2D(listeX, listeY, r, g, b);
}

void AbstractMonster::die() {
	EnvironmentUtils::killMonster(this);
}

int signe(float x) {
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}

void AbstractMonster::act() {
	
	float speedX = IA->getPlace()->getWidth() / slow;
	float speedY = IA->getPlace()->getHeight() / slow;

	float coeffX = (IA->getPlace()->getAncrageX() + IA->getPlace()->getWidth() / 2) - x;
	float coeffY = (IA->getPlace()->getAncrageY() + IA->getPlace()->getHeight() / 2) - y;
	if (fabs(coeffX) < speedX && fabs(coeffY) < speedY) {
		x = IA->getPlace()->getAncrageX() + IA->getPlace()->getWidth() / 2;
		y = IA->getPlace()->getAncrageY() + IA->getPlace()->getHeight() / 2;
		blockIA = false;
	}
	else {
		if(fabs(coeffX) < FLT_EPSILON) {
			y += speedY * signe(coeffY);
		}
		else {
			x += speedX * signe(coeffX);
		}
	}
	if (!blockIA) {
		WayFrame* frame = IA->getPlace();
		IA->goForward();
		WayFrame* frame2 = IA->getPlace();
		if(frame == frame2) {
			die();
		}
		blockIA = true;
	}
	if (pv <= 0) {
		die();
	}
}
