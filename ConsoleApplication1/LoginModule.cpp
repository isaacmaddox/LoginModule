#include <iostream>
#include <string>

#include "LoginModule.h"
#include "Console.cpp"

void LoginModule::Run()
{
	MainLoop();
}


void LoginModule::Login()
{
	std::string username;
	std::string password;

	GetUserInput("Enter your username:", username, true);
	GetUserInput("Enter your password:", password, false);

	DBRecord result = m_Database.Find(m_Cryptographer.EncryptVigenere(username));

	if (!result.found || m_Cryptographer.DecryptVigenere(result.value) != password)
	{
		std::cout << "Invalid username or password\n";
		return;
	}
	
	std::cout << "Welcome, " << username << std::endl;
	std::cout << "SHHH! Your MFA code for this session is " << m_Validation.GenerateMFA() << std::endl;
}

void LoginModule::Signup()
{
	std::string username = "";
	std::string password = "";
	int passwordAttempts = 0;

	GetUserInput("Enter your username:", username, true);
	GetUserInput("Enter your password:", password, false);

	while (!m_PasswordHandler.IsValidPassword(password))
	{
		++passwordAttempts;

		if (passwordAttempts >= MAX_PASSWORD_ATTEMPTS)
		{
			std::cout << "You will be assigned a default password. It will be sent to you in a secure email\n";
			password = m_PasswordHandler.GenerateDefaultPassword();
			break;
		}
		else {
			std::cout << "You have entered an invalid password. You have " << MAX_PASSWORD_ATTEMPTS - passwordAttempts << " attempt(s) remaining\n";
		}

		GetUserInput("Enter your password:", password, false);
	}

	if (m_Database.Insert(m_Cryptographer.EncryptVigenere(username), m_Cryptographer.EncryptVigenere(password)))
	{
		std::cout << "You have been signed up!\n";
	}
	else
	{
		std::cout << "This username is already in use!\n";
	}

}

void LoginModule::MainLoop()
{
	while (true)
	{
		char userChoice = PromptUser();

		switch (userChoice)
		{
		case 'L':
		case 'l':
			Login();
			break;
		case 'S':
		case 's':
			Signup();
			break;
		case 'Q':
		case 'q':
			std::exit(0);
			break;
		default:
			std::cout << "Invalid choice!\n";
			break;
		}

		std::cout << std::endl;
	}
}

char LoginModule::PromptUser()
{
	std::string userChoice;

	GetUserInput("Do you want to (L)ogin, (S)ignup, or (Q)uit?", userChoice, true);

	return userChoice.at(0);
}

void LoginModule::GetUserInput(std::string prompt, std::string& val, bool echo)
{
	SetStdinEcho(echo);

	std::cout << prompt << " ";

	getline(std::cin, val);

	SetStdinEcho(true);
}