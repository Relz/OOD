#include "IShape.h"
#include "ShapeCreator.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	ifstream inputFile("input.txt");

	string line;
	while (getline(inputFile, line))
	{
		stringstream stringStream(line);
		unique_ptr<IShape> shape(ShapeCreator::Create(stringStream));
		if (shape)
		{
			cout << shape->ToString() << "\n";
		}
	}

	return EXIT_SUCCESS;
}