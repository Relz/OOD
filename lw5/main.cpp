#include "Creator/CircleCreator.h"
#include "Creator/RectangleCreator.h"
#include "Creator/TriangleCreator.h"
#include "Printer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string ParseShapeName(stringstream& stringStream)
{
	string shapeName;
	stringStream >> shapeName;
	shapeName.pop_back();
	return shapeName;
}

unique_ptr<ShapeCreator> CreateCreatorFromType(string const& type)
{
	if (type == "RECTANGLE")
	{
		return move(RectangleCreator::GetInstance());
	}
	else if (type == "TRIANGLE")
	{
		return move(TriangleCreator::GetInstance());
	}
	else if (type == "CIRCLE")
	{
		return move(CircleCreator::GetInstance());
	}
}

int main()
{
	ifstream inputFile("input.txt");

	Printer printer;
	string line;
	while (getline(inputFile, line))
	{
		stringstream stringStream(line);
		string shapeName = ParseShapeName(stringStream);
		unique_ptr<ShapeCreator> shapeCreator = move(CreateCreatorFromType(shapeName));
		unique_ptr<IShape> shape = shapeCreator->Create(stringStream);
		if (shape)
		{
			shape->Print(printer);
		}
	}

	return EXIT_SUCCESS;
}
