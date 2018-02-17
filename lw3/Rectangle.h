#ifndef LW1_RECTANGLE_H
#define LW1_RECTANGLE_H

#include "Parser.h"
#include "Point.h"
#include "Shape.h"
#include <string>

using namespace std;

class Rectangle : public Shape
{
public:
	explicit Rectangle(const string& shapeName)
		: Shape(shapeName)
	{
	}

	double GetArea() const override
	{
		return abs(m_point1.GetY() - m_point2.GetY()) * abs(m_point1.GetX() - m_point2.GetX());
	}

	double GetPerimeter() const override
	{
		return (abs(m_point1.GetY() - m_point2.GetY()) + abs(m_point1.GetX() - m_point2.GetX())) * 2;
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
