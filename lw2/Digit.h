#ifndef LW2_DIGIT_H
#define LW2_DIGIT_H

#include <unordered_map>

using namespace std;

enum class Digit
{
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	NONE
};

class DigitExtensions
{
public:
	static Digit CreateFromCharacter(char character)
	{
		if (characterToDigit.find(character) == characterToDigit.end())
		{
			return Digit::NONE;
		}
		else
		{
			return characterToDigit.at(character);
		}
	}

	static char ToCharacter(Digit digit)
	{
		return digitToCharacter.at(digit);
	}

private:
	static const unordered_map<char, Digit> characterToDigit;
	static const unordered_map<Digit, char> digitToCharacter;
};

const unordered_map<char, Digit> DigitExtensions::characterToDigit = {
	{ '0', Digit::ZERO },
	{ '1', Digit::ONE },
	{ '2', Digit::TWO },
	{ '3', Digit::THREE },
	{ '4', Digit::FOUR },
	{ '5', Digit::FIVE },
	{ '6', Digit::SIX },
	{ '7', Digit::SEVEN },
	{ '8', Digit::EIGHT },
	{ '9', Digit::NINE }
};

const unordered_map<Digit, char> DigitExtensions::digitToCharacter = {
	{ Digit::ZERO, '0' },
	{ Digit::ONE, '1' },
	{ Digit::TWO, '2' },
	{ Digit::THREE, '3' },
	{ Digit::FOUR, '4' },
	{ Digit::FIVE, '5' },
	{ Digit::SIX, '6' },
	{ Digit::SEVEN, '7' },
	{ Digit::EIGHT, '8' },
	{ Digit::NINE, '9' },
	{ Digit::NONE, ' ' }
};

#endif //LW2_DIGIT_H
