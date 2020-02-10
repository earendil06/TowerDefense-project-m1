#include "AbstractFrame.h"
#include <GraphicPrimitives.h>


AbstractFrame::AbstractFrame(int _i, int _j, float ancX, float ancY, float sizeW, float sizeH) : ancrageX(ancX), ancrageY(ancY), width(sizeW), height(sizeH), i(_i), j(_j), r(0), g(0), b(0) {}




AbstractFrame::AbstractFrame(const AbstractFrame& other) : AbstractFrame(other.i, other.j, other.ancrageX, other.ancrageY, other.width, other.height)
{
	r = other.r;
	g = other.g;
	b = other.b;
}

AbstractFrame::AbstractFrame(): AbstractFrame(0, 0, 0, 0, 0, 0) {
	
}

AbstractFrame::~AbstractFrame()
{
}

float AbstractFrame::getAncrageX() const {
	return ancrageX;
}

float AbstractFrame::getAncrageY() const {
	return ancrageY;
}

float AbstractFrame::getWidth() const {
	return width;
}

float AbstractFrame::getHeight() const {
	return height;
}

int AbstractFrame::getI() const {
	return i;
}

int AbstractFrame::getJ() const {
	return j;
}

bool AbstractFrame::ok_for_tower() const { return okForTower; }
void AbstractFrame::set_ok_for_tower(bool ok_for_tower) { okForTower = ok_for_tower; }

void AbstractFrame::draw() {
	GraphicPrimitives::drawFillRect2D(ancrageX, ancrageY, width, height, r, g, b);
	GraphicPrimitives::drawOutlinedRect2D(ancrageX, ancrageY, width, height, 0.0f, 0.0f, 0.0f);
}

void AbstractFrame::setRGB(float _r, float _g, float _b) {
	r = _r;
	g = _g;
	b = _b;
}
