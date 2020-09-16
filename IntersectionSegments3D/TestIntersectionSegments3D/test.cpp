#include "pch.h"

TEST(TestIntersection, Intersect) {
	Segment3D first = Segment3D(Vector3D(5, 5, 5));
	Segment3D second = Segment3D(Vector3D(0, 2, 0), Vector3D(7, 2, 7));

	Vector3D result;
	EXPECT_TRUE (OperationsSegment3D::Intersect(first, second, result));
	EXPECT_EQ(result, Vector3D(2, 2, 2));
}

TEST(TestIntersection, Collinear) {
	Segment3D first = Segment3D(Vector3D(5, 5, 5));
	Segment3D second = Segment3D(Vector3D(2, 2, 2), Vector3D(7, 7, 7));

	Vector3D result;
	EXPECT_FALSE(OperationsSegment3D::Intersect(first, second, result));
	EXPECT_TRUE(OperationsSegment3D::Collinear(first, second));
}

TEST(TestIntersection, InRange) {
	Segment3D first = Segment3D(Vector3D(5, 5, 5));
	Segment3D second = Segment3D(Vector3D(10, 2, 10), Vector3D(7, 2, 7));

	Vector3D result;
	EXPECT_FALSE(OperationsSegment3D::Intersect(first, second, result));
	EXPECT_TRUE(OperationsSegment3D::InRange(first, result));
	EXPECT_FALSE(OperationsSegment3D::InRange(second, result));
}

TEST(TestIntersection, Crossing) {
	Segment3D first = Segment3D(Vector3D(0, 1, 1), Vector3D(1, 0, 1));
	Segment3D second = Segment3D(Vector3D(0, 1, 0), Vector3D(1, 0, 0));

	Vector3D result;
	EXPECT_FALSE(OperationsSegment3D::Intersect(first, second, result));
	EXPECT_FALSE(OperationsSegment3D::Collinear(first, second));
}