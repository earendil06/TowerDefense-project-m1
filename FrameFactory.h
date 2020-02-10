#pragma once
#include "AbstractFrame.h"
#include "WayFrame.h"
#include "LandFrame.h"

class FrameFactory
{
public:
	static AbstractFrame* fromChar(int, int, char);
	static AbstractFrame* fromChar(int, int, char, float, float, float, float);

private:
	FrameFactory(){};
	~FrameFactory(){};
};

inline AbstractFrame* FrameFactory::fromChar(int i, int j, char c) {
	return FrameFactory::fromChar(i, j, c, 0, 0, 0, 0);
}

inline AbstractFrame* FrameFactory::fromChar(int i, int j, char c, float ancX, float ancY, float width, float height) {
	switch (c) {
	case 'W':
		return new WayFrame(i, j, ancX, ancY, width, height);
	case 'A':
		return new WayFrame(i, j, ancX, ancY, width, height, false, true);
	case 'D':
		return new WayFrame(i, j, ancX, ancY, width, height, true, false);
	case 'L':
		return new LandFrame(i, j, ancX, ancY, width, height);
	default: break;
	}
	return nullptr;
}
