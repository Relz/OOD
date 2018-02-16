#ifndef LW2_DIGITEXTENSIONS_H
#define LW2_DIGITEXTENSIONS_H

#include "Digit.h"

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

	static Digit Multiply(Digit a, Digit b, Digit& carried)
	{
		int multiple = ToInt(a) * ToInt(b) + ToInt(carried);
		carried = CreateFromInt(multiple / 10);
		return CreateFromInt(multiple % 10);
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

#endif //LW2_DIGITEXTENSIONS_H
