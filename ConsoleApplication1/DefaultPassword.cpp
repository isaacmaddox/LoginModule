#include <random>
#include <sstream>

#include "DefaultPassword.h"

std::string DefaultPassword::GenerateDefaultPassword()
{
	std::ostringstream result;

	std::random_device rand;
	std::mt19937 rng(rand());
	std::uniform_int_distribution<std::mt19937::result_type> number(0, 9);
	std::uniform_int_distribution<std::mt19937::result_type> capital(65, 90);
	std::uniform_int_distribution<std::mt19937::result_type> lowercase(97, 122);
	std::uniform_int_distribution<std::mt19937::result_type> counter(1, DEFAULT_PASSWORD_LENGTH / 2 - 2);

	uint32_t numCapitals = counter(rng);
	uint32_t numLowercase = counter(rng);

	while (result.str().length() < numCapitals)
	{
		char letter = capital(rng);
		result << letter;
	}

	while (result.str().length() < numCapitals + numLowercase)
	{
		char letter = lowercase(rng);
		result << letter;
	}

	while (result.str().length() < DEFAULT_PASSWORD_LENGTH)
	{
		int num = number(rng);
		result << num;
	}

	return result.str();
}