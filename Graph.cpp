#include "Graph.h"
#include "EnvironmentUtils.h"
#include "World.h"
#include <set>
#include <map>


Edge::Edge(WayFrame* _elt1, WayFrame* _elt2) : source(_elt1), target(_elt2){}
Edge::Edge(const Edge& other) : source(other.source), target(other.target) {}

Edge::~Edge() {
	delete source, target;
}

Graph::Graph(Matrix<AbstractFrame*>* matrix) {
	for (int i = 0; i < matrix->getNbLines(); i++) {
		for(int j = 0; j < matrix->getNbColumns(); j++) {
			if (dynamic_cast<WayFrame*>(matrix->getValue(i, j)) != nullptr) {
				if (static_cast<WayFrame*>(matrix->getValue(i, j))->isDeparture()) {
					departure = static_cast<WayFrame*>(matrix->getValue(i, j));
				}
				else if (static_cast<WayFrame*>(matrix->getValue(i, j))->isArrival()) {
					arrival = static_cast<WayFrame*>(matrix->getValue(i, j));
				}
				vertexes.push_back(static_cast<WayFrame*>(matrix->getValue(i, j)));
				std::vector<std::pair<int, int>> coordsToGo = EnvironmentUtils::possiblesCoordsToGo(World::getMatrix(), World::getMatrix()->couplesArround(i, j));
				int k = 0;
				for (int idx = 0; idx < coordsToGo.size(); idx++) {
					addEdge(new Edge(static_cast<WayFrame*>(matrix->getValue(i, j)), static_cast<WayFrame*>(matrix->getValue(coordsToGo.at(idx).first, coordsToGo.at(idx).second))));
				}
			}
		}
	}
}

Graph::Graph(): departure(nullptr), arrival(nullptr) {}
Graph::Graph(const Graph& g): edges(g.edges), vertexes(g.vertexes), departure(g.departure), arrival(g.arrival) { }

Graph::~Graph(){
	delete[] departure, arrival;
}

void Graph::addEdge(Edge* edge) {
	edges.push_back(edge);
}

std::vector<WayFrame*> Graph::getNeighbours(WayFrame* where) const {
	std::vector<WayFrame*> result;
	for (Edge* edge : edges) {
		if (edge->source == where) {
			result.push_back(edge->target);
		}
	}
	return result;
}

std::map<WayFrame*, WayFrame*> Graph::dijkstra(WayFrame* source, WayFrame* target) const{
	std::map<WayFrame*, int> min_distance;
	std::map<WayFrame*, WayFrame*> parents;
	for (WayFrame* frame : vertexes) {
		min_distance[frame] = INT_MAX;
		parents[frame] = nullptr;
	}
	min_distance[source] = 0;

	std::set<std::pair<int, WayFrame*>> active_vertices;

	active_vertices.insert({ 0, source });

	while (!active_vertices.empty()) {
		WayFrame* where = active_vertices.begin()->second;
		if (where == target) return parents;
		active_vertices.erase(active_vertices.begin());
		for (WayFrame* ed : getNeighbours(where)) {
			if (min_distance[ed] > min_distance[where] + 1) {
				active_vertices.erase({ min_distance[ed], ed });
				min_distance[ed] = min_distance[where] + 1;
				parents[ed] = where;
				active_vertices.insert({ min_distance[ed], ed });
			}
		}
	}
	return parents;
}

std::vector<WayFrame*> Graph::path(WayFrame* source, WayFrame* target) const{
	std::map<WayFrame*, WayFrame*> parents = dijkstra(source, target);
	std::vector<WayFrame*> path;
	WayFrame* frame = arrival;
	do {
		path.push_back(frame);
		frame = parents[frame];
		if (frame == nullptr) {
			break;
		}
	} while (frame != departure);
	std::reverse(path.begin(), path.end());
	return path;
}
