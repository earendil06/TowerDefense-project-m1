#pragma once
#include "AbstractIA.h"
#include <vector>

class IAShortestPath : public AbstractIA
{
private:
	std::vector<WayFrame*> path;
	int indexPath;

public:
	IAShortestPath();
	~IAShortestPath();


	void goForward() override;
};

