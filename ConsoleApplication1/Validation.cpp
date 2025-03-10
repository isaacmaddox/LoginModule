#include <random>

#include "Validation.h"
#include "InvalidPasswordException.h"
#include "SQLInjectionError.h"
#include "IntegerOverflowError.h"

bool Validation::SqlInjection(const std::string& input)
{
	for (const auto& character : m_DisallowedChars)
	{
		if (input.find(character) != std::string::npos)
		{
			throw SQLInjectionError("The input provided contains possible SQL injection");
		}
	}

	return true;
}

bool Validation::PasswordPolicy(const std::string& input)
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

	for (int i = 0; i < 4; ++i)
	{
		if (!checks[i])
		{
			throw InvalidPasswordException("The password you entered is invalid.");
		}
	}
}

bool Validation::IntegerOverflow(const std::string& input)
{
	if (input.length() > 10) return false;

	try
	{
		stoi(input);
		return true;
	}
	catch (std::exception e)
	{
		throw IntegerOverflowError("The number entered may result in an integer overflow");
	}
}

/**
 * Adapted from https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
 */
uint32_t Validation::GenerateMFA()
{
	std::random_device rand;
	std::mt19937 rng(rand());
	std::uniform_int_distribution<std::mt19937::result_type> dist(1000000, INT_MAX);

	return dist(rng);
}