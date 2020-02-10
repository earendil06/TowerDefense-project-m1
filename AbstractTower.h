#pragma once
#include "Actionable.h"
#include "Drawable.h"
#include "LandFrame.h"
#include "AbstractMonster.h"

class AbstractTower :
	public Actionable, public Drawable
{
private:
	int waitShooter;
	int currentWait = 0;
	float distanceArea;
	LandFrame* place;
	float r, g, b;
	int level;

public:
	AbstractTower();
	AbstractTower(LandFrame*);
	~AbstractTower();

	void shot(AbstractMonster*) const;
	void act() override;
	void draw() override;
	float distanceTo(AbstractMonster*) const;
};

