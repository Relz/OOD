#ifndef LW2_DIGIT_H
#define LW2_DIGIT_H

#include <limits>
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
		if (m_characterToDigit.find(character) == m_characterToDigit.end())
		{
			return Digit::NONE;
		}
		else
		{
			return m_characterToDigit.at(character);
		}
	}

	static char ToCharacter(Digit digit)
	{
		return m_digitToCharacter.at(digit);
	}

	static Digit Accumulate(Digit a, Digit b, Digit& carried)
	{
		int sum = ToInt(a) + ToInt(b) + ToInt(carried);
		carried = CreateFromInt(sum / 10);
		return CreateFromInt(sum % 10);
	}

	static Digit Subtract(Digit a, Digit b, Digit& borrowed)
	{
		int difference = ToInt(a) - ToInt(b) - ToInt(borrowed);
		if (difference < 0)
		{
			borrowed = Digit::ONE;
			return CreateFromInt(difference + 10);
		}
		borrowed = Digit::ZERO;
		return CreateFromInt(difference);
	}

private:
	static int ToInt(Digit digit)
	{
		return m_digitToUInt.at(digit);
	}

	static Digit CreateFromInt(int uInt)
	{
		return m_uIntToDigit.at(uInt);
	}

private:
	static const unordered_map<char, Digit> m_characterToDigit;
	static const unordered_map<Digit, char> m_digitToCharacter;
	static const unordered_map<Digit, int> m_digitToUInt;
	static const unordered_map<int, Digit> m_uIntToDigit;
};

const unordered_map<char, Digit> DigitExtensions::m_characterToDigit = {
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

const unordered_map<Digit, char> DigitExtensions::m_digitToCharacter = {
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

const unordered_map<Digit, int> DigitExtensions::m_digitToUInt = {
	{ Digit::ZERO, 0 },
	{ Digit::ONE, 1 },
	{ Digit::TWO, 2 },
	{ Digit::THREE, 3 },
	{ Digit::FOUR, 4 },
	{ Digit::FIVE, 5 },
	{ Digit::SIX, 6 },
	{ Digit::SEVEN, 7 },
	{ Digit::EIGHT, 8 },
	{ Digit::NINE, 9 },
	{ Digit::NONE, numeric_limits<int>::max() },
};

const unordered_map<int, Digit> DigitExtensions::m_uIntToDigit = {
	{ 0, Digit::ZERO },
	{ 1, Digit::ONE },
	{ 2, Digit::TWO },
	{ 3, Digit::THREE },
	{ 4, Digit::FOUR },
	{ 5, Digit::FIVE },
	{ 6, Digit::SIX },
	{ 7, Digit::SEVEN },
	{ 8, Digit::EIGHT },
	{ 9, Digit::NINE },
	{ numeric_limits<int>::max(), Digit::NONE },
};

#endif //LW2_DIGIT_H
