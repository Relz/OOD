#include "../../LongInteger/LongInteger.h"
#include "gtest/gtest.h"
#include <sstream>

using namespace std;

TEST(copy_assignment, copy_digits)
{
	LongInteger longInteger1({ Digit::ONE, Digit::THREE, Digit::NONE, Digit::FIVE });
	LongInteger longInteger2;
	longInteger2 = longInteger1;
	stringstream stringStream1;
	stringStream1 << longInteger1;
	stringstream stringStream2;
	stringStream2 << longInteger2;
	EXPECT_EQ(stringStream1.str(), stringStream2.str());
}

TEST(move_assignment, moves_digits)
{
	LongInteger longInteger1({ Digit::ONE, Digit::THREE, Digit::NONE, Digit::FIVE });
	stringstream stringStream1;
	stringStream1 << longInteger1;
	LongInteger longInteger2;
	longInteger2 = move(longInteger1);
	stringstream stringStream2;
	stringStream2 << longInteger2;
	EXPECT_EQ(stringStream1.str(), stringStream2.str());
}
