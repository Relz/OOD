#include "../../LongInteger/LongInteger.h"
#include "gtest/gtest.h"
#include <sstream>

using namespace std;

TEST(minus_operator, returns_difference_of_two_long_integers)
{
	LongInteger longInteger1({ Digit::THREE, Digit::EIGHT, Digit::ONE });
	LongInteger longInteger2({ Digit::TWO, Digit::FOUR, Digit::SIX });
	EXPECT_EQ(longInteger1 - longInteger2, LongInteger({ Digit::ONE, Digit::THREE, Digit::FIVE }));
}
