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

	void GetArea(LongInteger & result) const override
	{
		result = LongInteger::PI * m_radius * m_radius;
		LongInteger::RemoveDigitsFromEnd(result, 2);
	}

	void GetPerimeter(LongInteger & result) const override
	{
		result = LongInteger({Digit::TWO}) * LongInteger::PI * m_radius;
		LongInteger::RemoveDigitsFromEnd(result, 2);
	}

	friend istream& operator>>(istream& is, unique_ptr<Circle>& circle)
	{
		string centerPointArgumentString;
		string radiusArgumentString;
		is >> centerPointArgumentString >> radiusArgumentString;

		stringstream(Parser::GetPointString(centerPointArgumentString)) >> circle->m_centerPoint;
		LongInteger::CreateFromString(Parser::GetString(radiusArgumentString), circle->m_radius);

		return is;
	}

private:
	Point m_centerPoint;
	LongInteger m_radius;
};

#endif //LW1_CIRCLE_H
