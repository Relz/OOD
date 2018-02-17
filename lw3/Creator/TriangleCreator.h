#ifndef LW3_TRIANGLECREATOR_H
#define LW3_TRIANGLECREATOR_H

#include "../IShape.h"
#include "../Triangle.h"
#include "ShapeCreator.h"
#include <memory>

using namespace std;

class TriangleCreator : public ShapeCreator
{
public:
	static unique_ptr<TriangleCreator> GetInstance()
	{
		if (!m_instance)
		{
			m_instance = make_unique<TriangleCreator>();
		}
		return move(m_instance);
	}

	unique_ptr<IShape> Create(stringstream& stringStream) const final
	{
		unique_ptr<Triangle> result = make_unique<Triangle>("TRIANGLE");
		stringStream >> result;
		return result;
	}

private:
	static unique_ptr<TriangleCreator> m_instance;
};

unique_ptr<TriangleCreator> TriangleCreator::m_instance = nullptr;

#endif //LW3_TRIANGLECREATOR_H
