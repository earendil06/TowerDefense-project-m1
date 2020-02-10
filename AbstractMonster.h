#pragma once
#include "Actionable.h"
#include "Drawable.h"
#include "AbstractIA.h"

class AbstractMonster : public Actionable, public Drawable
{
private:
	AbstractIA* IA;
	float r, g, b;
	int pv;
	float slow;
	float x, y;
	bool blockIA;

public:
	AbstractMonster(char);
	~AbstractMonster();

	void setPV(int);
	void setSlow(int);


	float getX() const;
	float getY() const;

	void draw() override;
	void die();
	void act() override;
};

