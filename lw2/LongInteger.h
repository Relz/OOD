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
				m_digits.insert(m_digits.begin(), digit);
			}
		}
	}

	friend ostream& operator<<(ostream& os, LongInteger const& longInteger)
	{
		for (auto it = longInteger.m_digits.rbegin(); it != longInteger.m_digits.rend(); ++it)
		{
			os << DigitExtensions::ToCharacter(*it);
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

	static LongInteger Accumulate(LongInteger const& a, LongInteger const& b)
	{
		LongInteger result;
		result.m_digits.resize(max(a.m_digits.size(), b.m_digits.size()));

		Digit carried = Digit::ZERO;
		for (size_t i = 0; i < result.m_digits.size(); ++i)
		{
			result.Set(i, DigitExtensions::Accumulate(a.Get(i), b.Get(i), carried));
		}
		if (carried != Digit::ZERO)
		{
			result.Set(result.m_digits.size(), carried);
		}
		return result;
	}

	static LongInteger Subtract(LongInteger const& a, LongInteger const& b)
	{
		LongInteger result = a;

		Digit borrowed = Digit::ZERO;
		for (size_t i = 0; i < result.m_digits.size(); ++i)
		{
			result.Set(i, DigitExtensions::Subtract(a.Get(i), b.Get(i), borrowed));
		}
		RemoveExtraZeros(result);
		return result;
	}

	static LongInteger Multiply(LongInteger const& a, LongInteger const& b)
	{
		LongInteger result;
		result.m_digits.resize(max(a.m_digits.size(), b.m_digits.size()));

		return result;
	}

	static LongInteger Divide(LongInteger const& a, LongInteger const& b)
	{
		LongInteger result;
		result.m_digits.resize(max(a.m_digits.size(), b.m_digits.size()));

		return result;
	}

private:
	vector<Digit> m_digits;

	Digit Get(size_t index) const
	{
		return index < m_digits.size() ? m_digits.at(index) : Digit::ZERO;
	}

	void Set(size_t index, Digit digit)
	{
		if (index >= m_digits.size())
		{
			m_digits.resize(index + 1);
		}
		m_digits[index] = digit;
	}

	static void RemoveExtraZeros(LongInteger& longInteger)
	{
		size_t actualSize = longInteger.m_digits.size();
		for (size_t i = longInteger.m_digits.size() - 1; i != SIZE_MAX; --i)
		{
			if (longInteger.m_digits.at(i) != Digit::ZERO)
			{
				actualSize = i + 1;
				break;
			}
		}
		longInteger.m_digits.resize(actualSize);
	}
};

#endif //LW2_LONGINTEGER_H
