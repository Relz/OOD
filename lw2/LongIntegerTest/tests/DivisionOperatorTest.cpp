#include "../../LongInteger/LongInteger.h"
#include "gtest/gtest.h"
#include <sstream>

using namespace std;

TEST(division_operator, returns_quotient_of_two_long_integers)
{
	{
		LongInteger longInteger1({ Digit::NINE, Digit::THREE, Digit::SEVEN, Digit::TWO, Digit::SIX });
		LongInteger longInteger2({ Digit::TWO, Digit::FOUR, Digit::SIX });
		EXPECT_EQ(longInteger1 / longInteger2, LongInteger({ Digit::THREE, Digit::EIGHT, Digit::ONE }));
	}
	{
		LongInteger longInteger1({ Digit::NINE, Digit::THREE, Digit::SEVEN, Digit::TWO, Digit::SIX });
		LongInteger longInteger2({ Digit::ZERO });
		EXPECT_THROW(longInteger1 / longInteger2, overflow_error);
	}
}
