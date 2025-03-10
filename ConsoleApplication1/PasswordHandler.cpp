#include "PasswordHandler.h"

bool PasswordHandler::IsValidPassword(const std::string& input)
{
	try {
		m_Validation.SqlInjection(input);
		m_Validation.PasswordPolicy(input);
	}
	catch (std::exception& e)
	{
		return e.what();
	}
}

std::string PasswordHandler::GenerateDefaultPassword()
{
	return m_DefaultPassword.GenerateDefaultPassword();
}