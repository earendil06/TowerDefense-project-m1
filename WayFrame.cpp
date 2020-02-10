#include "WayFrame.h"
#include <GraphicPrimitives.h>


WayFrame::WayFrame(int _i, int _j, float ancX, float ancY, float sizeW, float sizeH) : WayFrame(_i, _j, ancX, ancY, sizeW, sizeH, false, false){

}

WayFrame::WayFrame(int _i, int _j, float ancX, float ancY, float sizeW, float sizeH, bool b_d, bool b_a) : AbstractFrame(_i, _j, ancX, ancY, sizeW, sizeH), departure(b_d), arrival(b_a){
	okForTower = false;
	if (arrival) {
		setRGB(1.0f, 0.0f, 0.0f);
	}
	else if (departure) {
		setRGB(0.0f, 1.0f, 0.0f);
	}
	else {
		setRGB(0.55f, 0.27f, 0.07f);
	}
}

WayFrame::WayFrame() : AbstractFrame(), departure(false), arrival(false) {}
WayFrame::WayFrame(const WayFrame& w): AbstractFrame(w.i, w.j, w.ancrageX, w.ancrageY, w.width, w.height), departure(w.departure), arrival(w.arrival) { }

WayFrame::~WayFrame()
{
}

bool WayFrame::isDeparture() const {
	return departure;
}

bool WayFrame::isArrival() const {
	return arrival;
}
