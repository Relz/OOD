#include "IVisitor.h"
#include <iostream>

using namespace std;

class Printer : public IVisitor
{
public:
	void PrintShape(Rectangle const& rectangle) const final
	{
		cout << rectangle.ToString() << "\n";
	}

	void PrintShape(Triangle const& triangle) const final
	{
		cout << triangle.ToString() << "\n";
	}

	void PrintShape(Circle const& circle) const final
	{
		cout << circle.ToString() << "\n";
	}
};
