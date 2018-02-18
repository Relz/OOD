#ifndef LW1_RECTANGLE_H
#define LW1_RECTANGLE_H

#include "Parser.h"
#include "Point.h"
#include "Shape.h"
#include "MathHelper.h"
#include <string>

using namespace std;

class Rectangle : public Shape
{
public:
	explicit Rectangle(const string& shapeName)
		: Shape(shapeName)
	{
	}

	LongInteger GetArea() const override
	{
		LongInteger xDifference = LongInteger::CalculateDifference(m_point1.GetX(), m_point2.GetX());
		LongInteger yDifference = LongInteger::CalculateDifference(m_point1.GetY(), m_point2.GetY());
		return xDifference * yDifference;
	}

	LongInteger GetPerimeter() const override
	{
		LongInteger xDifference = LongInteger::CalculateDifference(m_point1.GetX(), m_point2.GetX());
		LongInteger yDifference = LongInteger::CalculateDifference(m_point1.GetY(), m_point2.GetY());
		return (xDifference + yDifference) * LongInteger({Digit::TWO});
	}

	friend istream& operator>>(istream& is, unique_ptr<Rectangle>& rectangle)
	{
		string point1ArgumentString;
		string point2ArgumentString;
		is >> point1ArgumentString >> point2ArgumentString;

		stringstream(Parser::GetPointString(point1ArgumentString)) >> rectangle->m_point1;
		stringstream(Parser::GetPointString(point2ArgumentString)) >> rectangle->m_point2;

		return is;
	}

private:
	Point m_point1;
	Point m_point2;
};

#endif //LW1_RECTANGLE_H
