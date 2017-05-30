#include "Message.h"
#include <iostream>


Message::Message(std::string message)
{
	this->message = message;
}

Message::Message() {

}

Message::~Message()
{
}

int Message::operator()() {
	if (message == "exit")
		return -1;
	std::cout << "La stringa " << message << " e' lunga " << message.length() << std::endl;
	return 0;
}

void Message::setMessage() {
	std::cout << "Inserisci una stringa" << std::endl;
	std::cin >> message;
}
void Message::setMessage(std::string message) {
	this->message = message;
}

void Message::clear() {
	message.clear();
}