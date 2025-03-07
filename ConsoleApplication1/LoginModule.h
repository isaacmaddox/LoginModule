#pragma once

#include <map>
#include <string>
#include "Validation.h"

class LoginModule
{
private:
	std::map<std::string, std::string> m_Database;
	Validation m_Validation;

	const int MAX_PASSWORD_ATTEMPTS = 2;

private:
	void ReadDatabase();
	void MainLoop();
	char PromptUser();
	void Login();
	void Signup();
	void GetUserInput(std::string prompt, std::string& val, bool echo);

public:
	void Run();
};

