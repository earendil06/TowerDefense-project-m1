#pragma once
#include <iostream>
#include "Drawable.h"

class AbstractFrame : public Drawable
{

protected:
	float ancrageX, ancrageY;
	float width, height;
	int i, j;
	float r, g, b;
	bool okForTower = false;


public:
	AbstractFrame(int, int, float, float, float, float);
	AbstractFrame(const AbstractFrame&);
	AbstractFrame();
	~AbstractFrame();

	float getAncrageX() const;
	float getAncrageY() const;
	float getWidth() const;
	float getHeight() const;
	int getI() const;
	int getJ() const;


	bool ok_for_tower() const;
	void set_ok_for_tower(bool);

	void draw() override;
	void setRGB(float, float, float);
};

