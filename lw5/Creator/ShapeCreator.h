#ifndef LW1_SHAPECREATOR_H
#define LW1_SHAPECREATOR_H

#include "../IShape.h"
#include <memory>
#include <sstream>
#include <unordered_map>

using namespace std;

class ShapeCreator
{
public:
	virtual unique_ptr<IShape> Create(stringstream& stringStream) const = 0;
};

#endif //LW1_SHAPECREATOR_H
