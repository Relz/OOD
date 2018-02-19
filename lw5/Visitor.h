#ifndef LW4_VISITOR_H
#define LW4_VISITOR_H

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

class Visitor
{
public:
	virtual void PrintShape(Rectangle& rectangle) const = 0;
	virtual void PrintShape(Triangle& triangle) const = 0;
	virtual void PrintShape(Circle& circle) const = 0;
};

#endif //LW4_VISITOR_H
