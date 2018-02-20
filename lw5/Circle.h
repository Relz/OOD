#ifndef LW1_CIRCLE_H
#define LW1_CIRCLE_H

#include "Parser.h"
#include "Point.h"
#include "Shape.h"
#include <string>

using namespace std;

class Circle : public Shape
{
public:
	explicit Circle(const string& shapeName)
		: Shape(shapeName)
	{
	}

	LongInteger GetArea() const override
	{
		return LongInteger::PI * m_radius * m_radius;
	}

	LongInteger GetPerimeter() const override
	{
		return LongInteger({ Digit::TWO }) * LongInteger::PI * m_radius;
	}

	void Print(IVisitor& printer) const
	{
		printer.PrintShape(*this);
	}

	friend istream& operator>>(istream& is, unique_ptr<Circle>& circle)
	{
		string centerPointArgumentString;
		string radiusArgumentString;
		is >> centerPointArgumentString >> radiusArgumentString;

		stringstream(Parser::GetPointString(centerPointArgumentString)) >> circle->m_centerPoint;
		circle->m_radius = LongInteger::CreateFromString(Parser::GetString(radiusArgumentString));

		return is;
	}

private:
	Point m_centerPoint;
	LongInteger m_radius;
};

#endif //LW1_CIRCLE_H
