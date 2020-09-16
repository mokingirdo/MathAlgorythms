#pragma once
#include "Segment3D.h"
#include <cmath>

static class OperationsSegment3D
{
public:
	//returns true if there is an intersection point and writes its value to result
	//returns false if there are no intersections or if the segments partially match
	static bool Intersect(Segment3D first, Segment3D second, Vector3D &result);
	static bool InRange(Segment3D segment, Vector3D dot);
	static bool Collinear(Segment3D first, Segment3D second);
};