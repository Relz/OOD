#include "../../LongInteger/LongInteger.h"
#include "gtest/gtest.h"
#include <sstream>

using namespace std;

TEST(less_operator, returns_true_if_long_integer_is_less_than_another_one)
{
	{
		LongInteger longInteger1({ Digit::ONE, Digit::THREE, Digit::NONE, Digit::FOUR });
		LongInteger longInteger2({ Digit::ONE, Digit::THREE, Digit::NONE, Digit::FIVE });
		EXPECT_TRUE(longInteger1 < longInteger2);
	}
	{
		LongInteger longInteger1({ Digit::ONE, Digit::THREE, Digit::NONE, Digit::FOUR });
		LongInteger longInteger2({ Digit::ONE, Digit::THREE, Digit::FIVE });
		EXPECT_TRUE(longInteger1 < longInteger2);
	}
}
