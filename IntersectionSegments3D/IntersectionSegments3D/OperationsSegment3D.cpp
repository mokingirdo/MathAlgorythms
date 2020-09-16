#include "OperationsSegment3D.h"

 bool  OperationsSegment3D::Intersect(Segment3D first, Segment3D second, Vector3D &result)
{
     double x, y, z;
     double m1, p1, l1;
     double m2, p2, l2;
     double t, s;
     double z1, z2;

     //checking for matching / parallelism of lines
     if (OperationsSegment3D::Collinear(first, second))
     {
         return false;
     }

     //guide vectors of lines containing segments
     m1 = first.getEnd().getX() - first.getStart().getX();
     p1 = first.getEnd().getY() - first.getStart().getY();
     l1 = first.getEnd().getZ() - first.getStart().getZ();

     m2 = second.getEnd().getX() - second.getStart().getX();
     p2 = second.getEnd().getY() - second.getStart().getY();
     l2 = second.getEnd().getZ() - second.getStart().getZ();

     //parameters of parametric equations of a line
     s = (m1 * (second.getStart().getY() - first.getStart().getY()) - p1 * (second.getStart().getX() - first.getStart().getX())) / (m2 * p1 - p2 * m1);
     t = ((second.getStart().getX() - first.getStart().getX()) + s * m2) / m1;

     z1 = first.getStart().getZ() + l1 * t;
     z2 = second.getStart().getZ() + l2 * s;

     if (z1 == z2) {
         //coordinates of the intersection point
         double x = first.getStart().getX() + m1 * t;
         double y = first.getStart().getY() + p1 * t;
         double z = z1;

         result = Vector3D(x, y, z);

         //checking the intersection points of lines belong to segments
         if (OperationsSegment3D::InRange(first, result) && OperationsSegment3D::InRange(second, result))
         {
             return true;
         }
     }

     return false;
}


 bool OperationsSegment3D::InRange(Segment3D segment, Vector3D dot)
 {
     if (!((segment.getStart().getX() <= dot.getX()) && (segment.getEnd().getX() >= dot.getX())))
         if(!((segment.getStart().getX() >= dot.getX()) && (segment.getEnd().getX() <= dot.getX())))
     {
         return false;
     }

     if (!((segment.getStart().getY() <= dot.getY()) && (segment.getEnd().getY() >= dot.getY())))
         if (!((segment.getStart().getY() >= dot.getY()) && (segment.getEnd().getY() <= dot.getY())))
         {
             return false;
         }

     if (!((segment.getStart().getZ() <= dot.getZ()) && (segment.getEnd().getZ() >= dot.getZ())))
         if (!((segment.getStart().getZ() >= dot.getZ()) && (segment.getEnd().getZ() <= dot.getZ())))
         {
             return false;
         }

     return true;
 }
 bool OperationsSegment3D::Collinear(Segment3D first, Segment3D second)
 {

     double k1 = (first.getEnd().getX() - first.getStart().getX())/(second.getEnd().getX() - second.getStart().getX());
     double k2 = (first.getEnd().getY() - first.getStart().getY())/(second.getEnd().getY() - second.getStart().getY());
     double k3 = (first.getEnd().getZ() - first.getStart().getZ())/(second.getEnd().getZ() - second.getStart().getZ());

     if ((k1 == k2) && (k2 == k3))
     {
         return true;
     }

     return false;
 }