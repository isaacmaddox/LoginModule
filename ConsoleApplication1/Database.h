#pragma once

#include <string>
#include <map>

#include "Cryptographer.h"

struct DBRecord {
	bool found;
	std::string key;
	std::string value;
};

class Database
{
private:
	Cryptographer m_Cryptographer;

	std::string m_FilePath;
	std::map<std::string, std::string> m_DatabaseMap;

	bool changed;

private:
	void LoadDatabase();

public:
	Database(std::string filePath);
	DBRecord Find(const std::string& key);
	bool Insert(const std::string& key, const std::string& value);
	void SaveChanges();
};

