#include <iostream>
#include <map>
#include <string>
#include <fstream>

#include "LoginModule.h"
#include "Console.cpp"

#define str std::string

void LoginModule::Run()
{
	ReadDatabase();
	MainLoop();
}

void LoginModule::ReadDatabase()
{
	std::ifstream dbIn("db.txt");

	if (!dbIn.is_open())
	{
		std::cout << "Could not read database file.\n";
		return;
	}

	while (!dbIn.eof())
	{
		str username;
		str password;

		std::getline(dbIn, username);
		std::getline(dbIn, password);

		m_Database.insert(std::make_pair(username, password));
	}

	dbIn.close();
}

void LoginModule::Login()
{
	str username;
	str password;

	GetUserInput("Enter your username:", username, true);
	GetUserInput("Enter your password:", password, false);

	std::map<str, str>::iterator record = m_Database.find(username);

	if (record == m_Database.end())
	{
		std::cout << "Invalid username or password\n";
		return;
	}

	str _pwd = record->second;

	if (_pwd != password)
	{
		std::cout << "Incorrect username or \n";
		return;
	}
	
	std::cout << "Welcome, " << username << std::endl;
}

void LoginModule::Signup()
{
	str username;
	str password;

	GetUserInput("Enter your username:", username, true);
	GetUserInput("Enter your password:", password, false);

	std::map<str, str>::iterator record = m_Database.find(username);

	if (record != m_Database.end())
	{
		std::cout << "This username is already in use. Please pick another one.\n";
		return;
	}

	m_Database.insert(std::make_pair(username, password));

	std::cout << "You have been signed up!\n";
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
	str userChoice;

	std::cout << "Do you want to (L)ogin, (S)ignup, or (Q)uit? ";
	std::getline(std::cin, userChoice);

	return userChoice.at(0);
}

void LoginModule::GetUserInput(str prompt, str& val, bool echo)
{
	SetStdinEcho(echo);

	std::cout << prompt << " ";
	getline(std::cin, val);

	SetStdinEcho(true);
}