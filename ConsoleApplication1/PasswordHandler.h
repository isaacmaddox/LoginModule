#pragma once

#include "Validation.h"
#include "DefaultPassword.h"

class PasswordHandler
{
private:
	Validation m_Validation;
	DefaultPassword m_DefaultPassword;

public:
	PasswordHandler()
		: m_Validation(Validation()),
		m_DefaultPassword(DefaultPassword()) {};
	bool IsValidPassword(const std::string& input);
	std::string GenerateDefaultPassword();
};