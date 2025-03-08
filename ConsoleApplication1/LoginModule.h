#pragma once

#include <map>
#include <string>

#include "Database.h"
#include "Validation.h"
#include "Cryptographer.h"

class LoginModule
{
private:
	Database m_Database;
	Validation m_Validation;
	Cryptographer m_Cryptographer;

	const int MAX_PASSWORD_ATTEMPTS = 2;

private:
	void MainLoop();
	char PromptUser();
	void Login();
	void Signup();
	void GetUserInput(std::string prompt, std::string& val, bool echo);

public:
	LoginModule() : m_Database(Database("db.txt")) {};
	void Run();
};

