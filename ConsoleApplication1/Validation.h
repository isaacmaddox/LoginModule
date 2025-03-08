#pragma once

#include <map>
#include <string>

class Validation
{
private:
	std::map<std::string, int> m_MfaCodes;
	char m_DisallowedChars[4] {
		'/',
		'-',
		';',
		'\\'
	};

public:
	bool SqlInjection(std::string input);
	bool PasswordPolicy(std::string input);
	bool IntegerOverflow(std::string input);
	uint32_t GenerateMFA();
};

