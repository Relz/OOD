#ifndef LW1_TRIANGLE_H
#define LW1_TRIANGLE_H

#include "Parser.h"
#include "Point.h"
#include "Shape.h"
#include <string>
#include <math.h>

using namespace std;

class Triangle : public Shape
{
public:
	explicit Triangle(const string& shapeName)
		: Shape(shapeName)
	{
	}

	double GetArea() const override
	{
		return 0.5 * (((m_point1.GetX() - m_point3.GetX()) * (m_point2.GetY() - m_point3.GetY())) - ((m_point2.GetX() - m_point3.GetX()) * (m_point1.GetY() - m_point3.GetY())));
	}

	double GetPerimeter() const override
	{
		return GetSide(m_point2, m_point1) + GetSide(m_point3, m_point2) + GetSide(m_point3, m_point1);
	}

	friend istream& operator>>(istream& is, Triangle* triangle)
	{
		string point1ArgumentString;
		string point2ArgumentString;
		string point3ArgumentString;
		is >> point1ArgumentString >> point2ArgumentString >> point3ArgumentString;

		stringstream(Parser::GetPointString(point1ArgumentString)) >> triangle->m_point1;
		stringstream(Parser::GetPointString(point2ArgumentString)) >> triangle->m_point2;
		stringstream(Parser::GetPointString(point3ArgumentString)) >> triangle->m_point3;

		return is;
	}

private:
	Point m_point1;
	Point m_point2;
	Point m_point3;

	static double GetSide(Point const& point1, Point const& point2)
	{
		return sqrt(pow(point2.GetX() - point1.GetX(), 2) + pow(point2.GetY() - point1.GetY(), 2));
	}
};

#endif //LW1_TRIANGLE_H
