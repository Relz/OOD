#include "LongInteger/LongInteger.h"
#include <fstream>
#include <regex>
#include <unordered_map>

using namespace std;

unordered_map<char, function<LongInteger(LongInteger const&, LongInteger const&)>> operationFunction = {
	{ '+', [](LongInteger const& left, LongInteger const& right) { return left + right; } },
	{ '-', [](LongInteger const& left, LongInteger const& right) { return left - right; } },
	{ '*', [](LongInteger const& left, LongInteger const& right) { return left * right; } },
	{ '/', [](LongInteger const& left, LongInteger const& right) {return left / right; } }
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
		try
		{
			LongInteger operationResult = operationFunction.at(operation)(operand1, operand2);
			cout << operand1 << " " << operation << " " << operand2 << " = " <<  operationResult << "\n";
		}
		catch (overflow_error & exception)
		{
			cout << exception.what() << "\n";
		}
	}
	return EXIT_SUCCESS;
}
