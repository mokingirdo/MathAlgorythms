#include "Vector3D.h"

Vector3D::Vector3D(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Vector3D:: getX()
{
	return x;
}

double Vector3D:: getY()
{
	return y;
}

double Vector3D::getZ()
{
	return z;
}

bool operator==(const Vector3D& left, const Vector3D& right)
{
	if ((left.x == right.x) && (left.y == right.y) && (left.z == right.z))
	{
		return true;
	}
	return false;
}

Vector3D::~Vector3D()
{
}

