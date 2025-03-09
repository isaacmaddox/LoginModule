#include <fstream>

#include "Database.h"

Database::Database(std::string filePath)
	: m_FilePath(filePath), changed(0)
{
	LoadDatabase();
};

void Database::SaveChanges()
{
	if (!changed) return;

	std::ofstream dbOut("db.txt");

	if (!dbOut.is_open())
	{
		std::exit(1);
	}

	for (const auto& record : m_DatabaseMap)
	{
		dbOut << record.first << std::endl << record.second << std::endl;
	}
}

void Database::LoadDatabase()
{
	std::ifstream dbIn("db.txt");

	if (!dbIn.is_open())
	{
		return;
	}

	while (!dbIn.eof())
	{
		std::string username;
		std::string password;

		std::getline(dbIn, username);
		std::getline(dbIn, password);

		m_DatabaseMap.insert(std::make_pair(username, password));
	}

	dbIn.close();
}

DBRecord Database::Find(std::string& key)
{
	DBRecord recordResult;
	std::map<std::string, std::string>::iterator result = m_DatabaseMap.find(key);

	if (result == m_DatabaseMap.end())
	{
		return {
			false,
			key,
			""
		};
	}

	return {
		true,
		key,
		result->second
	};
}

bool Database::Insert(std::string& key, std::string& value)
{
	if (Find(key).found) return false;

	m_DatabaseMap.insert(std::make_pair(key, value));
	changed = 1;

	return true;
}