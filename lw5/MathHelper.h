#ifndef LW4_MATHHELPER_H
#define LW4_MATHHELPER_H

class MathHelper
{
public:
	static int GetDifference(int a, int b)
	{
		return a > b ? a - b : b - a;
	}
};

#endif //LW4_MATHHELPER_H
