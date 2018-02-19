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

	LongInteger GetArea() const override = 0;

	LongInteger GetPerimeter() const override = 0;

	std::string ToString() const final
	{
		return m_shapeName + ":" + " P=" + LongInteger::ToString(GetPerimeter()) + ";" + " S=" + LongInteger::ToString(GetArea());
	}

private:
	std::string m_shapeName;
};

#endif //LW1_SHAPE_H
