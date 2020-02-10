#include "AbstractIA.h"
#include "World.h"
#include "EnvironmentUtils.h"

AbstractIA::AbstractIA() : place(EnvironmentUtils::getDeparture(World::getMatrix()))
{
}


AbstractIA::~AbstractIA()
{
}

WayFrame* AbstractIA::getPlace() const {
	return place;
}

void AbstractIA::setPlace(WayFrame* place) {
	this->place = place;
}
