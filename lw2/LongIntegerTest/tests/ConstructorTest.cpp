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

TEST(constructor, initialize_long_integer_with_zero_by_default)
{
	LongInteger longInteger;
	stringstream stringStream;
	stringStream << longInteger;
	EXPECT_EQ(stringStream.str(), "0");
}

TEST(copy_constructor, copy_digits)
{
	LongInteger longInteger1({ Digit::ONE, Digit::THREE, Digit::NONE, Digit::FIVE });
	LongInteger longInteger2(longInteger1);
	stringstream stringStream1;
	stringStream1 << longInteger1;
	stringstream stringStream2;
	stringStream2 << longInteger2;
	EXPECT_EQ(stringStream1.str(), stringStream2.str());
}

TEST(move_constructor, moves_digits)
{
	LongInteger longInteger1({ Digit::ONE, Digit::THREE, Digit::NONE, Digit::FIVE });
	stringstream stringStream1;
	stringStream1 << longInteger1;
	LongInteger longInteger2(move(longInteger1));
	stringstream stringStream2;
	stringStream2 << longInteger2;
	EXPECT_EQ(stringStream1.str(), stringStream2.str());
}
