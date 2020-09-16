#include "Segment3D.h"


Segment3D::Segment3D(Vector3D start, Vector3D end)
{
	this->start = start;
	this->end = end;
}

Vector3D Segment3D::getStart()
{
	return start;
}

Vector3D Segment3D::getEnd()
{
	return end;
}

Segment3D::~Segment3D()
{

}