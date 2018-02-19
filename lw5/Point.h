#ifndef LW1_POINT_H
#define LW1_POINT_H

#include "LongInteger/LongInteger.h"
#include <regex>

using namespace std;

class Point
{
public:
	LongInteger GetX() const
	{
		return m_x;
	}

	LongInteger GetY() const
	{
		return m_y;
	}

	void SetX(LongInteger x)
	{
		m_x = x;
	}

	void SetY(LongInteger y)
	{
		m_y = y;
	}

	friend istream& operator>>(istream& is, Point& point)
	{
		string pointString;
		is >> pointString;
		smatch matches;
		regex_search(pointString, matches, regex("([0-9]+),([0-9]+)$"));
		point.m_x = LongInteger::CreateFromString(matches.str(1));
		point.m_y = LongInteger::CreateFromString(matches.str(2));
		return is;
	}

private:
	LongInteger m_x;
	LongInteger m_y;
};

#endif //LW1_POINT_H
