#pragma once

#include <string>

class Cryptographer
{
private:
	std::string m_AlphaKey = "ARGOSROCK";
	int m_NumberKey = 1963;

	const int MIN_CHAR = '!';
	const int MAX_CHAR = '~';
	const int CHAR_RANGE = MAX_CHAR - MIN_CHAR + 1;

public:
	std::string EncryptVigenere(const std::string& input);
	std::string DecryptVigenere(const std::string& input);
	std::string EncryptNumber(int& input);
	int DecryptNumber(const std::string& input);
};

