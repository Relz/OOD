#ifndef LW3_CIRCLECREATOR_H
#define LW3_CIRCLECREATOR_H

#include "../Circle.h"
#include "../IShape.h"
#include "ShapeCreator.h"
#include <memory>

using namespace std;

class CircleCreator : public ShapeCreator
{
public:
	static unique_ptr<CircleCreator> GetInstance()
	{
		if (!m_instance)
		{
			CircleCreator::m_instance = unique_ptr<CircleCreator>(new CircleCreator());
		}
		return move(m_instance);
	}

	unique_ptr<IShape> Create(stringstream& stringStream) const final
	{
		unique_ptr<Circle> result = make_unique<Circle>("CIRCLE");
		stringStream >> result;
		return result;
	}

private:
	static unique_ptr<CircleCreator> m_instance;

	explicit CircleCreator() = default;
};

unique_ptr<CircleCreator> CircleCreator::m_instance = nullptr;

#endif //LW3_CIRCLECREATOR_H
