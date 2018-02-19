#include "Visitor.h"
#include <iostream>

using namespace std;

class Printer : public Visitor
{
public:
	void PrintShape(Rectangle& rectangle) const final
	{
		cout << rectangle.ToString() << "\n";
	}

	void PrintShape(Triangle& triangle) const final
	{
		cout << triangle.ToString() << "\n";
	}

	void PrintShape(Circle& circle) const final
	{
		cout << circle.ToString() << "\n";
	}
};
