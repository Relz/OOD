#ifndef LW1_ISHAPE_H
#define LW1_ISHAPE_H

#include "IVisitor.h"
#include <string>

using namespace std;

class IShape
{
public:
	virtual LongInteger GetArea() const = 0;
	virtual LongInteger GetPerimeter() const = 0;
	virtual string ToString() const = 0;
	virtual void Print(Visitor& printer) const = 0;
};

#endif //LW1_ISHAPE_H
