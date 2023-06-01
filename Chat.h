#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Messenger.h"
#include "User.h"


class Chat : public Messenger {
public:

	std::string sender;
	std::string receiver;
	int num_of_message = 0;
	std::vector<std::string> mess;
};