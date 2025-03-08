#include <sstream>

#include "Cryptographer.h"


std::string Cryptographer::EncryptVigenere(std::string& input)
{
	std::ostringstream result;

	int keyLen = m_AlphaKey.length();

	for (int i = 0; i < input.length(); ++i)
	{
		char plainChar = input.at(i);
		char keyChar = m_AlphaKey.at(i % keyLen);
		
		char newChar = MIN_CHAR + (((plainChar - MIN_CHAR) + (keyChar - MIN_CHAR) + CHAR_RANGE) % CHAR_RANGE);

		result << newChar;
	}

	return result.str();
}

std::string Cryptographer::DecryptVigenere(std::string& input)
{
	std::ostringstream result;

	int keyLen = m_AlphaKey.length();

	for (int i = 0; i < input.length(); ++i)
	{
		char plainChar = input.at(i);
		char keyChar = m_AlphaKey.at(i % keyLen);

		char newChar = MIN_CHAR + (((plainChar - MIN_CHAR) - (keyChar - MIN_CHAR) + CHAR_RANGE) % CHAR_RANGE);

		result << newChar;
	}

	return result.str();
}

std::string Cryptographer::EncryptNumber(int& input)
{
	std::ostringstream result;
	std::string inputString = std::to_string(input);
	std::string keyString = std::to_string(m_NumberKey);
	int keyLen = keyString.length();

	for (int i = 0; i < inputString.length(); ++i)
	{
		char at = inputString[i];
		int toShift = at - '0';
		int key = keyString.at(i % keyLen) - '0';

		char shifted = (key - toShift + 100) % 10 + '0';

		result << shifted;
	}

	return result.str();
}

int Cryptographer::DecryptNumber(std::string& input)
{
	std::ostringstream result;
	std::string keyString = std::to_string(m_NumberKey);
	int keyLen = keyString.length();

	for (int i = 0; i < input.length(); ++i)
	{
		int toShift = input.at(i) - '0';
		int key = keyString.at(i % keyLen) - '0';

		int shifted = (key - toShift + 100) % 10;

		result << shifted;
	}

	return std::stoi(result.str());
}