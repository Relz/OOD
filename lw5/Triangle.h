#ifndef LW1_TRIANGLE_H
#define LW1_TRIANGLE_H

#include "Parser.h"
#include "Point.h"
#include "Shape.h"
#include <string>

using namespace std;

class Triangle : public Shape
{
public:
	explicit Triangle(const string& shapeName)
		: Shape(shapeName)
	{
	}

	LongInteger GetArea() const override
	{
		LongInteger halfPerimeter = GetPerimeter() / LongInteger({Digit::TWO});
		return LongInteger::CalculateSquareRoot(halfPerimeter * (halfPerimeter - CalculateSideA()) * (halfPerimeter - CalculateSideB()) * (halfPerimeter - CalculateSideC()));
	}

	LongInteger GetPerimeter() const override
	{
		return CalculateSideA() + CalculateSideB() + CalculateSideC();
	}

	void Accept(IVisitor & printer) const
	{
		printer.PrintShape(*this);
	}

	friend istream& operator>>(istream& is, unique_ptr<Triangle>& triangle)
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

	LongInteger CalculateSideA() const
	{
		return CalculateSide(m_point2, m_point1);
	}

	LongInteger CalculateSideB() const
	{
		return CalculateSide(m_point3, m_point2);
	}

	LongInteger CalculateSideC() const
	{
		return CalculateSide(m_point3, m_point1);
	}

	static LongInteger CalculateSide(Point const& point1, Point const& point2)
	{
		LongInteger xDifference = LongInteger::CalculateDifference(point1.GetX(), point2.GetX());
		LongInteger yDifference = LongInteger::CalculateDifference(point1.GetY(), point2.GetY());
		return LongInteger::CalculateSquareRoot(xDifference * xDifference + yDifference * yDifference);
	}
};

#endif //LW1_TRIANGLE_H
