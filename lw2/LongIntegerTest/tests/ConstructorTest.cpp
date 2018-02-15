#include "../../LongInteger/LongInteger.h"
#include "gtest/gtest.h"
#include <sstream>

using namespace std;

TEST(constructor, initialize_long_integer_with_specified_digits_except_none)
{
	LongInteger longInteger({ Digit::ONE, Digit::THREE, Digit::NONE, Digit::FIVE });
	stringstream stringStream;
	stringStream << longInteger;
	EXPECT_EQ(stringStream.str(), "135");
}
