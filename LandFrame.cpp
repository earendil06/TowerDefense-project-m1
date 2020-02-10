#include "LandFrame.h"


LandFrame::LandFrame(int _i, int _j, float ancX, float ancY, float sizeW, float sizeH) : AbstractFrame(_i, _j, ancX, ancY, sizeW, sizeH)
{
	setRGB(0.0f, 0.5f, 0.0f);
	okForTower = true;
}

LandFrame::LandFrame() : AbstractFrame() {}

LandFrame::~LandFrame()
{
}
