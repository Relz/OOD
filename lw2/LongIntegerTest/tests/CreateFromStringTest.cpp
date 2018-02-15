#include "../../LongInteger/LongInteger.h"
#include "gtest/gtest.h"
#include <sstream>

using namespace std;

TEST(create_from_string, creates_long_integer_from_string_of_digits)
{
	LongInteger longInteger1 = LongInteger::CreateFromString("1234567890");
	stringstream stringStream1;
	stringStream1 << longInteger1;
	EXPECT_EQ(stringStream1.str(), "1234567890");
}
