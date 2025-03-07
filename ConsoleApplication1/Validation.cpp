#include "Validation.h"

bool Validation::SqlInjection(std::string input)
{
	for (const auto& character : m_DisallowedChars)
	{
		if (input.find(character) != std::string::npos) return false;
	}

	return true;
}

bool Validation::PasswordPolicy(std::string input)
{
	// 0: At least 1 lowercase
	// 1: At least 1 uppercase
	// 2: At least 1 number
	// 3: Length check
	bool checks[4] = { 0, 0, 0, input.length() >= 8 && input.length() <= 12};

	for (const auto& character : input)
	{
		if (character >= 97 && character <= 122) checks[0] = 1;
		if (character >= 65 && character <= 90) checks[1] = 1;
		if (character >= 48 && character <= 57) checks[2] = 1;
	}

	return checks[0] && checks[1] && checks[2] && checks[3];
}

bool Validation::IntegerOverflow(std::string input)
{
	if (input.length() > 10) return false;

	try
	{
		stoi(input);
		return true;
	}
	catch (std::exception e)
	{
		return false;
	}
}