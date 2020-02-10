#pragma once
#include "AbstractFrame.h"

class WayFrame : public AbstractFrame
{

private:
	bool departure;
	bool arrival;

	
public:
	WayFrame(int, int, float, float, float, float);
	WayFrame(int, int, float, float, float, float, bool, bool);
	WayFrame();
	WayFrame(const WayFrame&);
	~WayFrame();

	bool isDeparture() const;
	bool isArrival() const;
};

