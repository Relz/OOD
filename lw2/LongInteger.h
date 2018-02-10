#ifndef LW2_LONGINTEGER_H
#define LW2_LONGINTEGER_H

#include "Digit.h"
#include <iostream>
#include <vector>

using namespace std;

class LongInteger
{
public:
	explicit LongInteger(vector<Digit> const& digits = { Digit::ZERO })
	{
		for (Digit digit : digits)
		{
			if (digit != Digit::NONE)
			{
				m_digits.emplace_back(digit);
			}
		}
	}

	friend ostream& operator<<(ostream& os, LongInteger const& longInteger)
	{
		for (Digit digit : longInteger.m_digits)
		{
			os << DigitExtensions::ToCharacter(digit);
		}
		return os;
	}

	static LongInteger CreateFromString(string const& str)
	{
		vector<Digit> digits;
		for (char ch : str)
		{
			digits.emplace_back(DigitExtensions::CreateFromCharacter(ch));
		}
		return std::move(LongInteger(digits));
	}

private:
	vector<Digit> m_digits;
};

#endif //LW2_LONGINTEGER_H
