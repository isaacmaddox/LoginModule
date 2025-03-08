#pragma once

#include <string>
#include <map>

struct DBRecord {
	bool found;
	std::string key;
	std::string value;
};

class Database
{
private:
	std::string m_FilePath;
	std::map<std::string, std::string> m_DatabaseMap;

private:
	void LoadDatabase();

public:
	Database(std::string filePath);
	DBRecord Find(std::string& key);
	bool Insert(std::string& key, std::string& value);
};

