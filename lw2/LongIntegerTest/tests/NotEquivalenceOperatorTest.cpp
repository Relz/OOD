#include "../../LongInteger/LongInteger.h"
#include "gtest/gtest.h"
#include <sstream>

using namespace std;

TEST(not_equivalence_operator, returns_true_if_long_integers_have_different_digits)
{
	{
		LongInteger longInteger1({ Digit::ONE, Digit::TWO, Digit::NONE, Digit::FIVE });
		LongInteger longInteger2({ Digit::ONE, Digit::THREE, Digit::NONE, Digit::FIVE });
		EXPECT_TRUE(longInteger1 != longInteger2);
	}
	{
		LongInteger longInteger1({ Digit::ONE, Digit::THREE, Digit::NONE, Digit::NONE });
		LongInteger longInteger2({ Digit::ONE, Digit::THREE, Digit::FIVE });
		EXPECT_TRUE(longInteger1 != longInteger2);
	}
}
