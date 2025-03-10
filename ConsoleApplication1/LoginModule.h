#pragma once

#include <map>
#include <string>

#include "Database.h"
#include "Cryptographer.h"
#include "PasswordHandler.h"
#include "Validation.h"

class LoginModule
{
private:
	Database m_Database;
	Cryptographer m_Cryptographer;
	Validation m_Validation;
	PasswordHandler m_PasswordHandler;

	const int MAX_PASSWORD_ATTEMPTS = 2;

private:
	void MainLoop();
	char PromptUser();
	void Login();
	void Signup();
	void GetUserInput(std::string prompt, std::string& val, bool echo);

public:
	LoginModule() : m_Database(Database("db.txt")), 
		m_Cryptographer(Cryptographer()),
		m_Validation(Validation()),
		m_PasswordHandler(PasswordHandler()) {};
	void Run();
};

