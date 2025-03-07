#pragma once

#include <string>

class Cryptographer
{
private:
	std::string m_AlphaKey = "ARGOSROCK";
	int m_NumberKey = 1963;

	const char MIN_CHAR = '!';
	const char MAX_CHAR = '~';
	const char CHAR_RANGE = MAX_CHAR - MIN_CHAR + 1;

public:
	std::string EncryptVigenere(std::string& input);
	std::string DecryptVigenere(std::string& input);
};

