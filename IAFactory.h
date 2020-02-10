#pragma once
#include "IAShortestPath.h"
#include "IARandom.h"

class IAFactory
{
private:	
	IAFactory();
public:
	static const char ShortestPathIA = 's';
	static const char RandomIA = 'r';
	static AbstractIA* fromType(const char);
};

inline AbstractIA* IAFactory::fromType(const char c) {
	switch(c) {
	case ShortestPathIA : return new IAShortestPath();
	case RandomIA: return new IARandom();
	default: return nullptr;
	}
}
