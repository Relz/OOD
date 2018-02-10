#include "LongInteger.h"
#include <fstream>
#include <regex>

using namespace std;

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
		cout << operand1 << " " << operation << " " << operand2 << "\n";
	}
	return 0;
}
