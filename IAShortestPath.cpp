#include "IAShortestPath.h"
#include "World.h"
#include "EnvironmentUtils.h"


IAShortestPath::IAShortestPath() : indexPath(0) {
	Graph* g = World::getGraph();
	WayFrame* arrival = EnvironmentUtils::getArrival(World::getMatrix());
	path = g->path(getPlace(), arrival);
}


IAShortestPath::~IAShortestPath()
{
}

void IAShortestPath::goForward() {
	if (getPlace() != EnvironmentUtils::getArrival(World::getMatrix())) {
		setPlace(path.at(indexPath));
		indexPath++;
	}

}
