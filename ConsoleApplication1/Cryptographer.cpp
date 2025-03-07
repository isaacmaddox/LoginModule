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

		char newChar = MIN_CHAR + (((plainChar) - (keyChar - MIN_CHAR) + CHAR_RANGE) % CHAR_RANGE);

		result << newChar;
	}

	return result.str();
}