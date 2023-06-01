#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Messenger.h"
#include "Chat.h"

void page2(std::string uname);

class User : public Messenger {
public:
	std::map<std::string, Chat> SMS;
	void chat_on(std::string, std::string, std::string);
	void mailbox(std::string);
};