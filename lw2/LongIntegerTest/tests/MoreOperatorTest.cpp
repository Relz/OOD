#include "../../LongInteger/LongInteger.h"
#include "gtest/gtest.h"
#include <sstream>

using namespace std;

TEST(more_operator, returns_true_if_long_integer_is_more_than_another_one)
{
	{
		LongInteger longInteger1({ Digit::ONE, Digit::THREE, Digit::NONE, Digit::SIX });
		LongInteger longInteger2({ Digit::ONE, Digit::THREE, Digit::NONE, Digit::FIVE });
		EXPECT_TRUE(longInteger1 > longInteger2);
	}
	{
		LongInteger longInteger1({ Digit::ONE, Digit::THREE, Digit::NONE, Digit::SIX });
		LongInteger longInteger2({ Digit::ONE, Digit::THREE, Digit::FIVE });
		EXPECT_TRUE(longInteger1 > longInteger2);
	}
}
