#include "../../LongInteger/LongInteger.h"
#include "gtest/gtest.h"
#include <sstream>

using namespace std;

TEST(plus_operator, returns_sum_of_two_long_integers)
{
	LongInteger longInteger1({ Digit::ONE, Digit::THREE, Digit::FIVE });
	LongInteger longInteger2({ Digit::TWO, Digit::FOUR, Digit::SIX });
	EXPECT_EQ(longInteger1 + longInteger2, LongInteger({ Digit::THREE, Digit::EIGHT, Digit::ONE }));
}
