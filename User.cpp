#include "User.h"

void User::chat_on(std::string uname, std::string recipient, std::string message) {
	int flag = 0;
	SMS[recipient].sender = uname;
	SMS[recipient].receiver = recipient;

	std::map<std::string, std::string>::iterator account;
	for (account = Messenger::Base.begin(); account != Messenger::Base.end(); account++) {
		if (account->first == recipient) {
			flag++;
		}
	}
	if (flag == 0) {
		std::cout << "Sorry! User is not found. Try one more time." << std::endl;
		page2(uname);
	}

	std::string cuname;
	cuname = uname;

	SMS[recipient].mess[SMS[recipient].num_of_message] = cuname;
	SMS[recipient].mess[SMS[recipient].num_of_message] = ": ";
	SMS[recipient].mess[SMS[recipient].num_of_message] = message;

	SMS[recipient].num_of_message++;
}


void User::mailbox(std::string uname) {
	std::cout << "\n \t Welcome to your mailbox, " << uname << "\n" << std::endl;
	std::cout << "Here is all received messages:" << std::endl;
	for (int i = 0; i < SMS[uname].num_of_message; i++) {
		std::cout << SMS[uname].mess[i];
		std::cout << "\a \n" << std::endl;
	}
}
