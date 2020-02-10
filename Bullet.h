#pragma once
#include "Drawable.h"
#include "Actionable.h"
#include "AbstractMonster.h"
#include "AbstractTower.h"

class Bullet :
	public Drawable, public Actionable
{
private:
	float x, y;
	AbstractMonster* target;
	const AbstractTower* source;
	float speed;

public:
	Bullet();
	Bullet(float, float, const AbstractTower*, AbstractMonster*);
	~Bullet();


	void draw() override;
	void act() override;
};

