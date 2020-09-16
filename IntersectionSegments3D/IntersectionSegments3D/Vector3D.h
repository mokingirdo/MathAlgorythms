#pragma once

class  Vector3D
{

public:

	Vector3D(double x = 0, double y = 0, double z = 0);

	double getX();
	double getY();
	double getZ();
	friend bool operator==(const Vector3D& left, const Vector3D& right);

	~ Vector3D();

private:

	double x;
	double y;
	double z;

};
