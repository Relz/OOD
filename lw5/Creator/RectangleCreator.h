#ifndef LW3_RECTANGLECREATOR_H
#define LW3_RECTANGLECREATOR_H

#include "../Rectangle.h"
#include "ShapeCreator.h"
#include <memory>

using namespace std;

class RectangleCreator : public ShapeCreator
{
public:
	static unique_ptr<RectangleCreator> GetInstance()
	{
		if (!RectangleCreator::m_instance)
		{
			RectangleCreator::m_instance = unique_ptr<RectangleCreator>(new RectangleCreator());
		}
		return move(RectangleCreator::m_instance);
	}

	unique_ptr<IShape> Create(stringstream& stringStream) const final
	{
		unique_ptr<Rectangle> result = make_unique<Rectangle>("RECTANGLE");
		stringStream >> result;
		return result;
	}

private:
	static unique_ptr<RectangleCreator> m_instance;

	explicit RectangleCreator() = default;
};

unique_ptr<RectangleCreator> RectangleCreator::m_instance = nullptr;

#endif //LW3_RECTANGLECREATOR_H
