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

	void GetArea(LongInteger & result) const override
	{
		LongInteger sideA;
		CalculateSideA(sideA);

		LongInteger sideB;
		CalculateSideB(sideB);

		LongInteger sideC;
		CalculateSideC(sideC);

		LongInteger halfPerimeter = move((sideA + sideB + sideC) / LongInteger({Digit::TWO}));
		LongInteger::CalculateSquareRoot(halfPerimeter * (halfPerimeter - sideA) * (halfPerimeter - sideB) * (halfPerimeter - sideC), result);
	}

	void GetPerimeter(LongInteger & result) const override
	{
		LongInteger sideA;
		CalculateSideA(sideA);

		LongInteger sideB;
		CalculateSideB(sideB);

		LongInteger sideC;
		CalculateSideC(sideC);

		result = move(sideA + sideB + sideC);
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

	void CalculateSideA(LongInteger & result) const
	{
		CalculateSide(m_point2, m_point1, result);
	}

	void CalculateSideB(LongInteger & result) const
	{
		CalculateSide(m_point3, m_point2, result);
	}

	void CalculateSideC(LongInteger & result) const
	{
		CalculateSide(m_point3, m_point1, result);
	}

	static void CalculateSide(Point const& point1, Point const& point2, LongInteger & result)
	{
		LongInteger xDifference;
		LongInteger::CalculateDifference(point1.GetX(), point2.GetX(), xDifference);
		LongInteger yDifference;
		LongInteger::CalculateDifference(point1.GetY(), point2.GetY(), yDifference);
		LongInteger::CalculateSquareRoot(xDifference * xDifference + yDifference * yDifference, result);
	}
};

#endif //LW1_TRIANGLE_H
