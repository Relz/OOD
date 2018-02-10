#include "LongInteger.h"
#include <fstream>
#include <regex>
#include <unordered_map>

using namespace std;

LongInteger Accumulate(LongInteger const& a, LongInteger const& b);
LongInteger Subtract(LongInteger const& a, LongInteger const& b);
LongInteger Multiply(LongInteger const& a, LongInteger const& b);
LongInteger Divide(LongInteger const& a, LongInteger const& b);

unordered_map<char, function<LongInteger(LongInteger const&, LongInteger const&)>> operationFunction = {
	{ '+', Accumulate },
	{ '-', Subtract },
	{ '*', Multiply },
	{ '/', Divide }
};

int main()
{
	ifstream inputFile("input.txt");

	string line;
	while (getline(inputFile, line))
	{
		smatch matches;
		regex_search(line, matches, regex(R"(([0-9\s]+)\s([-+*\/])\s([0-9\s]+))"));
		LongInteger operand1 = LongInteger::CreateFromString(matches.str(1));
		char operation = matches.str(2).at(0);
		LongInteger operand2 = LongInteger::CreateFromString(matches.str(3));
		cout << operand1 << " " << operation << " " << operand2 << " = " << operationFunction.at(operation)(operand1, operand2) << "\n";
	}
	return EXIT_SUCCESS;
}

LongInteger Accumulate(LongInteger const& a, LongInteger const& b)
{
	LongInteger result = a;

	return result;
}

LongInteger Subtract(LongInteger const& a, LongInteger const& b)
{
	LongInteger result = a;

	return result;
}

LongInteger Multiply(LongInteger const& a, LongInteger const& b)
{
	LongInteger result = a;

	return result;
}

LongInteger Divide(LongInteger const& a, LongInteger const& b)
{
	LongInteger result = a;

	return result;
}
