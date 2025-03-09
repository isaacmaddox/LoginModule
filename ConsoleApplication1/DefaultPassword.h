#pragma once

#include <string>

class DefaultPassword
{
private:
	int DEFAULT_PASSWORD_LENGTH = 12;

public:
	std::string GenerateDefaultPassword();
};

