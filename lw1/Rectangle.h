#ifndef LW1_RECTANGLE_H
#define LW1_RECTANGLE_H

#include "Point.h"
#include "Shape.h"
#include <iostream>
#include <memory>

using namespace std;

class Rectangle : public Shape
{
public:
	explicit Rectangle(const string& shapeName)
		: Shape(shapeName)
	{
	}

	unsigned int GetArea() const override
	{
		return static_cast<unsigned int>(abs(m_point1.GetY() - m_point2.GetY()) * abs(m_point1.GetX() - m_point2.GetX()));
	}

	unsigned int GetPerimeter() const override
	{
		return static_cast<unsigned int>((abs(m_point1.GetY() - m_point2.GetY()) + abs(m_point1.GetX() - m_point2.GetX())) * 2);
	}

	friend istream& operator>>(istream& is, Rectangle* rectangle)
	{
		string point1ArgumentString;
		string point2ArgumentString;
		is >> point1ArgumentString >> point2ArgumentString;

		stringstream(GetPointString(point1ArgumentString)) >> rectangle->m_point1;
		stringstream(GetPointString(point2ArgumentString)) >> rectangle->m_point2;

		return is;
	}

private:
	Point m_point1;
	Point m_point2;

	static string GetPointString(string const& pointArgumentString)
	{
		smatch matches;
		regex_search(pointArgumentString, matches, regex("[a-zA-Z0-9]+=([0-9]+,[0-9]+);$"));
		return matches.str(1);
	}
};

#endif //LW1_RECTANGLE_H
