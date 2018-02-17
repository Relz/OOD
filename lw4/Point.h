#ifndef LW1_POINT_H
#define LW1_POINT_H

#include <regex>

using namespace std;

class Point
{
public:
	int GetX() const
	{
		return m_x;
	}

	int GetY() const
	{
		return m_y;
	}

	void SetX(int x)
	{
		m_x = x;
	}

	void SetY(int y)
	{
		m_y = y;
	}

	friend istream& operator>>(istream& is, Point& point)
	{
		string pointString;
		is >> pointString;
		smatch matches;
		regex_search(pointString, matches, regex("([0-9]+),([0-9]+)$"));
		point.m_x = stoi(matches.str(1));
		point.m_y = stoi(matches.str(2));
		return is;
	}

private:
	int m_x = 0;
	int m_y = 0;
};

#endif //LW1_POINT_H
