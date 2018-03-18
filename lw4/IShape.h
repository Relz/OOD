#ifndef LW1_ISHAPE_H
#define LW1_ISHAPE_H

#include <string>

using namespace std;

class IShape
{
public:
	virtual void GetArea(LongInteger & result) const = 0;
	virtual void GetPerimeter(LongInteger & result) const = 0;
	virtual string ToString() const = 0;
};

#endif //LW1_ISHAPE_H
