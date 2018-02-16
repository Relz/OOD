#ifndef LW1_CIRCLE_H
#define LW1_CIRCLE_H

#include "Parser.h"
#include "Point.h"
#include "Shape.h"
#include <cmath>
#include <string>

using namespace std;

class Circle : public Shape
{
public:
	explicit Circle(const string& shapeName)
		: Shape(shapeName)
	{
	}

	double GetArea() const override
	{
		return M_PI * pow(m_radius, 2);
	}

	double GetPerimeter() const override
	{
		return 2 * M_PI * m_radius;
	}

	friend istream& operator>>(istream& is, Circle* circle)
	{
		string centerPointArgumentString;
		string radiusArgumentString;
		is >> centerPointArgumentString >> radiusArgumentString;

		stringstream(Parser::GetPointString(centerPointArgumentString)) >> circle->m_centerPoint;
		circle->m_radius = stod(Parser::GetString(radiusArgumentString));

		return is;
	}

private:
	Point m_centerPoint;
	double m_radius = 0;
};

#endif //LW1_CIRCLE_H
