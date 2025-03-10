#pragma once

#include <stdexcept>

class IntegerOverflowError : public std::exception
{
private:
	std::string m_Message;

public:
	IntegerOverflowError(const std::string& message) : m_Message(message) {};
	const char* what() const noexcept override { return m_Message.c_str(); };
};