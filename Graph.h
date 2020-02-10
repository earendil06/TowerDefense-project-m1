#pragma once
#include "WayFrame.h"
#include <vector>
#include "Matrix.h"
#include <map>

class Edge
{

public:
	WayFrame* source;
	WayFrame* target;
	Edge(WayFrame*, WayFrame*);
	Edge(const Edge&);
	~Edge();
};


class Graph
{
private:
	std::vector<Edge*> edges;
	std::vector<WayFrame*> vertexes;
	WayFrame* departure;
	WayFrame* arrival;

	std::map<WayFrame*, WayFrame*> dijkstra(WayFrame*, WayFrame*) const;
	std::vector<WayFrame*> getNeighbours(WayFrame*) const;


public:
	Graph();
	Graph(const Graph&);
	Graph(Matrix<AbstractFrame*>*);
	~Graph();

	void addEdge(Edge*);
	std::vector<WayFrame*> path(WayFrame*, WayFrame*) const;
};

