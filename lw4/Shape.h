#ifndef LW1_SHAPE_H
#define LW1_SHAPE_H

#include "IShape.h"
#include <sstream>

using namespace std;

class Shape : public IShape
{
public:
	Shape(std::string const& shapeName)
		: m_shapeName(shapeName)
	{
	}

	void GetArea(LongInteger & result) const override = 0;

	void GetPerimeter(LongInteger & result) const override = 0;

	std::string ToString() const final
	{
		LongInteger perimeter;
		GetPerimeter(perimeter);
		LongInteger area;
		GetArea(area);
		string perimeterString;
		LongInteger::ToString(perimeter, perimeterString);
		string areaString;
		LongInteger::ToString(area, areaString);
		return m_shapeName + ":" + " P=" + perimeterString + ";" + " S=" + areaString;
	}

private:
	std::string m_shapeName;
};

#endif //LW1_SHAPE_H
