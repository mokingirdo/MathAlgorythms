#pragma once
#include "Vector3D.h"

class Segment3D
{

public:
	Segment3D(Vector3D start = Vector3D(), Vector3D end = Vector3D());

	Vector3D getStart();
	Vector3D getEnd();

	~Segment3D();

private:

	Vector3D start;
	Vector3D end;
};
