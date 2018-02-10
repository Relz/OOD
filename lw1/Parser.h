#ifndef LW1_PARSER_H
#define LW1_PARSER_H

#include <regex>
#include <string>

using namespace std;

class Parser
{
public:
	static string GetPointString(string const& pointArgumentString)
	{
		smatch matches;
		regex_search(pointArgumentString, matches, regex("[a-zA-Z0-9]+[=|:]([0-9]+,[0-9]+);?$"));
		return matches.str(1);
	}

	static string GetString(string const& argumentString)
	{
		smatch matches;
		regex_search(argumentString, matches, regex("[a-zA-Z0-9]+[=|:]([0-9]+);?$"));
		return matches.str(1);
	}
};

#endif //LW1_PARSER_H
