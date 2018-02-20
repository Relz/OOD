#ifndef LW4_VISITOR_H
#define LW4_VISITOR_H

class Rectangle;
class Triangle;
class Circle;

class IVisitor
{
public:
	virtual void PrintShape(Rectangle const& rectangle) const = 0;
	virtual void PrintShape(Triangle const& triangle) const = 0;
	virtual void PrintShape(Circle const& circle) const = 0;
};

#endif //LW4_VISITOR_H
