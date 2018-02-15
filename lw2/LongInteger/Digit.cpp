#include "Digit.h"

const unordered_map<char, Digit> DigitExtensions::m_characterToDigit = { { '0', Digit::ZERO }, { '1', Digit::ONE }, { '2', Digit::TWO }, { '3', Digit::THREE }, { '4', Digit::FOUR },
	{ '5', Digit::FIVE }, { '6', Digit::SIX }, { '7', Digit::SEVEN }, { '8', Digit::EIGHT },
	{ '9', Digit::NINE } };

const unordered_map<Digit, char> DigitExtensions::m_digitToCharacter = { { Digit::ZERO, '0' }, { Digit::ONE, '1' }, { Digit::TWO, '2' }, { Digit::THREE, '3' }, { Digit::FOUR, '4' },
	{ Digit::FIVE, '5' }, { Digit::SIX, '6' }, { Digit::SEVEN, '7' }, { Digit::EIGHT, '8' },
	{ Digit::NINE, '9' }, { Digit::NONE, ' ' } };

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
