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
				m_digits.emplace(m_digits.begin(), digit);
			}
		}
	}

	LongInteger(LongInteger const& right)
	{
		if (this != &right)
		{
			m_digits = right.m_digits;
		}
	}

	LongInteger(LongInteger&& right) noexcept
	{
		if (this != &right)
		{
			m_digits = move(right.m_digits);
		}
	}

	LongInteger& operator=(LongInteger const& right)
	{
		if (this == &right)
		{
			return *this;
		}
		m_digits = right.m_digits;
		return *this;
	}

	LongInteger& operator=(LongInteger&& right) noexcept
	{
		if (this == &right)
		{
			return *this;
		}
		m_digits = move(right.m_digits);
		return *this;
	}

	friend ostream& operator<<(ostream& os, LongInteger const& longInteger)
	{
		for (auto it = longInteger.m_digits.rbegin(); it != longInteger.m_digits.rend(); ++it)
		{
			os << DigitExtensions::ToCharacter(*it);
		}
		return os;
	}

	friend bool operator==(LongInteger const& left, LongInteger const& right)
	{
		LongInteger a = left;
		LongInteger b = right;
		RemoveExtraZeros(a);
		RemoveExtraZeros(b);
		if (a.m_digits.size() != b.m_digits.size())
		{
			return false;
		}
		for (size_t i = a.m_digits.size() - 1; i != SIZE_MAX; --i)
		{
			if (a.Get(i) != b.Get(i))
			{
				return false;
			}
		}
		return true;
	}

	friend bool operator!=(LongInteger const& left, LongInteger const& right)
	{
		return !(left == right);
	}

	friend bool operator<(LongInteger const& left, LongInteger const& right)
	{
		LongInteger a = left;
		LongInteger b = right;
		RemoveExtraZeros(a);
		RemoveExtraZeros(b);
		if (a.m_digits.size() != b.m_digits.size())
		{
			return a.m_digits.size() < b.m_digits.size();
		}
		for (size_t i = a.m_digits.size() - 1; i != SIZE_MAX; --i)
		{
			if (a.Get(i) != b.Get(i))
			{
				return a.Get(i) < b.Get(i);
			}
		}
		return false;
	}

	friend bool operator>(LongInteger const& left, LongInteger const& right)
	{
		return left != right && !(left < right);
	}

	friend const LongInteger operator+(LongInteger const& left, LongInteger const& right)
	{
		LongInteger result;
		result.m_digits.resize(max(left.m_digits.size(), right.m_digits.size()));

		Digit carried = Digit::ZERO;
		for (size_t i = 0; i < result.m_digits.size(); ++i)
		{
			result.Set(i, DigitExtensions::Accumulate(left.Get(i), right.Get(i), carried));
		}
		if (carried != Digit::ZERO)
		{
			result.Set(result.m_digits.size(), carried);
		}
		return result;
	}

	friend const LongInteger operator-(LongInteger const& left, LongInteger const& right)
	{
		LongInteger result = left;

		Digit borrowed = Digit::ZERO;
		for (size_t i = 0; i < result.m_digits.size(); ++i)
		{
			result.Set(i, DigitExtensions::Subtract(left.Get(i), right.Get(i), borrowed));
		}
		RemoveExtraZeros(result);
		return result;
	}

	friend const LongInteger operator*(LongInteger const& left, LongInteger const& right)
	{
		vector<LongInteger> summands(right.m_digits.size());
		for (size_t i = 0; i < right.m_digits.size(); ++i)
		{
			Digit carried = Digit::ZERO;
			for (size_t j = 0; j < left.m_digits.size(); ++j)
			{
				summands.at(i).Set(j, DigitExtensions::Multiply(left.Get(j), right.Get(i), carried));
			}
			if (carried != Digit::ZERO)
			{
				summands.at(i).Set(summands.at(i).m_digits.size(), carried);
			}
			for (size_t k = 0; k < i; ++k)
			{
				summands.at(i).m_digits.emplace(summands.at(i).m_digits.begin(), Digit::ZERO);
			}
		}

		LongInteger result;
		for (LongInteger const& summand : summands)
		{
			result = result + summand;
		}
		return result;
	}

	friend const LongInteger operator/(LongInteger const& left, LongInteger const& right)
	{
		if (right == LongInteger())
		{
			throw overflow_error("Division by zero");
		}
		LongInteger result;
		LongInteger tmp2;
		while (tmp2 != left)
		{
			LongInteger multiplier({ Digit::ONE });
			LongInteger tmp = right;
			LongInteger previousMultiplier = multiplier;
			while (tmp2 + tmp < left)
			{
				previousMultiplier = multiplier;
				multiplier = multiplier + multiplier;
				tmp = right * multiplier;
			}
			tmp2 = tmp2 + right * previousMultiplier;
			result = result + previousMultiplier;
		}
		return result;
	}

	static LongInteger CreateFromString(string const& str)
	{
		vector<Digit> digits;
		for (char ch : str)
		{
			digits.emplace_back(DigitExtensions::CreateFromCharacter(ch));
		}
		return move(LongInteger(digits));
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
