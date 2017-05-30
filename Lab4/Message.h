#pragma once
#include <string>
#include <mutex>
class Message
{
private:
	
	std::string message;
	

public:
	Message();
	Message(std::string message);
	~Message();
	int operator()();
	void setMessage();
	void Message::setMessage(std::string message);
	void clear();
};



