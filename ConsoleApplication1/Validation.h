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
	bool SqlInjection(const std::string& input);
	bool PasswordPolicy(const std::string& input);
	bool IntegerOverflow(const std::string& input);
	uint32_t GenerateMFA();
};

