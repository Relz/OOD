#include "LongInteger.h"
#include <fstream>
#include <regex>
#include <unordered_map>

using namespace std;

unordered_map<char, function<LongInteger(LongInteger const&, LongInteger const&)>> operationFunction = {
	{ '+', LongInteger::Accumulate },
	{ '-', LongInteger::Subtract },
	{ '*', LongInteger::Multiply },
	{ '/', LongInteger::Divide }
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
