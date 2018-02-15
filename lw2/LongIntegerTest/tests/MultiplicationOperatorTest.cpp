#include "../../LongInteger/LongInteger.h"
#include "gtest/gtest.h"
#include <sstream>

using namespace std;

TEST(multiplication_operator, returns_result_of_multiplication_of_two_long_integers)
{
	LongInteger longInteger1({ Digit::THREE, Digit::EIGHT, Digit::ONE });
	LongInteger longInteger2({ Digit::TWO, Digit::FOUR, Digit::SIX });
	EXPECT_EQ(longInteger1 * longInteger2, LongInteger({ Digit::NINE, Digit::THREE, Digit::SEVEN, Digit::TWO, Digit::SIX }));
}
