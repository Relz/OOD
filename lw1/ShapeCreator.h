#ifndef LW1_SHAPECREATOR_H
#define LW1_SHAPECREATOR_H

#include "Circle.h"
#include "IShape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

class ShapeCreator
{
public:
	static IShape* Create(stringstream& stringStream)
	{
		string shapeName = ParseShapeName(stringStream);
		if (shapeNameToCreateFunction.find(shapeName) != shapeNameToCreateFunction.end())
		{
			return shapeNameToCreateFunction.at(shapeName)(stringStream);
		}
		return nullptr;
	}

private:
	static string ParseShapeName(stringstream& stringStream)
	{
		string shapeName;
		stringStream >> shapeName;
		shapeName.pop_back();
		return shapeName;
	}

	static IShape* CreateRectangle(stringstream& stringStream)
	{
		Rectangle* rectangle = new Rectangle("RECTANGLE");
		stringStream >> rectangle;
		return rectangle;
	}

	static IShape* CreateTriangle(stringstream& stringStream)
	{
		Triangle* triangle = new Triangle("TRIANGLE");
		stringStream >> triangle;
		return triangle;
	}

	static IShape* CreateCircle(stringstream& stringStream)
	{
		Circle* circle = new Circle("CIRCLE");
		stringStream >> circle;
		return circle;
	}

	static const unordered_map<string, function<IShape*(stringstream&)>> shapeNameToCreateFunction;
};

const unordered_map<string, function<IShape*(stringstream&)>> ShapeCreator::shapeNameToCreateFunction = {
	{ "RECTANGLE", CreateRectangle },
	{ "TRIANGLE", CreateTriangle },
	{ "CIRCLE", CreateCircle }
};

#endif //LW1_SHAPECREATOR_H
