#pragma once
#include "AbstractIA.h"
#include <set>

class IARandom : public AbstractIA
{
private:
	std::set<WayFrame*> placesVisited;

public:
	IARandom();
	~IARandom();

	static int randint(int, int);

	void goForward() override;
};

