#pragma once
#include "WayFrame.h"

class AbstractIA
{
private:
	WayFrame* place;

public:
	AbstractIA();
	virtual ~AbstractIA();

	WayFrame* getPlace() const;

	void setPlace(WayFrame*);
	virtual void goForward() = 0;
};

