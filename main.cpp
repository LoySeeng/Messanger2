#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Messenger.h"
#include "User.h"
#include "Chat.h"
#include "Server.h"
#include "Client.h"


Messenger Hell;
std::map <std::string, std::string> Messenger::Base;


void page1() {
    int flag = 0;
    int choice;

    std::cout << "\t \n \n Welcome to the Messenger '666'! \n" << std::endl;

    while (1) {
        std::cout << "\nWhat do you want to do:" << std::endl;
        std::cout << "1 - Sign Up, 2 - Sign In, 3 - Run away \n" << std::endl;
        std::cin >> choice;
        std::cout << "\n";
        switch (choice) {
        case 1: {
            std::string username;
            std::string pass;
            std::cout << "Create your login: ";
            std::cin >> username;
            std::cout << "Create your password: ";
            std::cin >> pass;

            std::map<std::string, std::string>::iterator account;
            if (Messenger::Base.empty()) {
                Messenger::Base[username] = pass;
            }
            else {
                for (account = Messenger::Base.begin(); account != Messenger::Base.end(); account++) {
                    if (account->first == username) {
                        std::cout << "Sorry! This login is occupied. Please, try another one." << std::endl;
                        break;
                    }
                    else {
                        Messenger::Base[username] = pass;
                        break;
                    }
                }
            }
            break;
        }
        case 2: {
            std::string log_username;
            std::string log_pass;
            std::cout << "Enter your login: ";
            std::cin >> log_username;
            std::cout << "Enter your password: ";;
            std::cin >> log_pass;

            std::map<std::string, std::string>::iterator account;
            for (account = Messenger::Base.begin(); account != Messenger::Base.end(); account++) {
                if (account->first == log_username && account->second == log_pass) {
                    std::cout << "\n WELCOME, " << log_username << "!! You have logged in successfully. \n";

                    flag = 1;
                    page2(log_username);
                    break;
                }
            }
            if (flag == 0) {
                std::cout << "Someting has gone wrong. Probably login or password is incorrect. Please, try again." << std::endl;
                break;
            }
            break;
        }
        case 3: {
            system("cls");
            std::cout << "\nYou could never run away... Just kidding. Goodbye, User!" << std::endl;
            exit(666);
            break;
        }
        default: {
            std::cout << "Please, choose a number between 1 - 3" << std::endl;
            break;
        }
        }
        if (flag == 1) {
            break;
        }
    }
}

std::map<std::string, User> list;

void page2(std::string uname) {
    system("cls");

    int choice2;
    int choice4;

    do {
        std::cout << "\n \n \n \n \t \t \t Welcome, " << uname << "! \n" << std::endl;
        
        std::cout << "Do you want to operate as a server or a client?" << std::endl;
        std::cout << "1 - Server, 2 - Client" << std::endl;
        int SC;
        std::cin >> SC;
        if (SC == 1) {
            void processRequest();
        }
        else if (SC == 2) {
            void sendRequest();
        }
        else {
            std::cout << "Can't establish connection. Continuing work in offline mode.\n" << std::endl;
        }

        std::cout << "What do you want to do:\n" << std::endl;
        std::cout << "1 - Check mailbox \n2 - Send a message to the person \n3 - Send a message to everyone \n4 - Log Out \n" << std::endl;

        std::cin >> choice2;
        switch (choice2) {
        case 1: {
            list[uname].mailbox(uname);

            if (SC == 1) {
                std::cout << "Last recived message: " << std::endl;
                length = sizeof(client);
                message_size = recvfrom(socket_file_descriptor, buffer, sizeof(buffer), 0, (struct sockaddr*)&client, &length);
                buffer[message_size] = '\0';
                std::cout << buffer << std::endl;
            }
            else if (SC == 2) {
                std::cout << "Last recived message: " << std::endl;
                recvfrom(socket_descriptor, buffer, sizeof(buffer), 0, nullptr, nullptr);
                std::cout << buffer << std::endl;
            }
            
            break;
        }
        case 2: {
            std::cout << "\nWho do you want to send a message to? To ";
            std::string reciepient;
            std::cin >> reciepient;
            std::string message;
            std::cout << "\nEnter your message: \n" << std::endl;
            std::cout << "\t";
            std::cin.ignore();
            std::cin >> SendMessage;
            message = SendMessage;
            if (SC == 1) {
                sendto(socket_file_descriptor, SendMessage, MESSAGE_BUFFER, 0, (struct sockaddr*)&client, sizeof(client));
            }
            else {
                sendto(socket_descriptor, SendMessage, MESSAGE_BUFFER, 0, nullptr, sizeof(serveraddress));
            }
            
            list[reciepient].chat_on(uname, reciepient, message);

            std::cout << "\nYour message has been sent successfully" << std::endl;
            break;
        }
        case 3: {
            std::vector<std::string> recivers;
            std::map<std::string, std::string>::iterator account;
            std::vector<std::string>::iterator Irec;

            std::cout << "\nBe careful! This message will be sent to everyone. \n" << std::endl;
            do {
                int flag = 0;
                std::string reciepient;
                std::cout << "\nEnter reciepient: ";
                std::cin >> reciepient;

                for (account = Messenger::Base.begin(); account != Messenger::Base.end(); account++) {
                    if (account->first == reciepient) {
                        flag++;
                    }
                }
                if (flag == 0) {
                    std::cout << "\nRecipient is not found! Please, try again." << std::endl;
                }
                recivers.push_back(reciepient);
                std::cout << "\nDo you want to add more recipients? 1 - Yes, 2 - No\n";
                std::cin >> choice4;
                if (choice4 != 1 && choice4 != 2) {
                    std::cout << "There were just to options: 1 and 2. Let's start over." << std::endl;
                }
            } while (choice4 != 2);
            std::string message;
            std::cout << "\nEnter your message:" << std::endl;
            std::cout << "\t";
            std::cin.ignore();
            std::getline(std::cin, message);
            for (Irec = recivers.begin(); Irec != recivers.end(); Irec++) {
                list[*Irec].chat_on(uname, *Irec, message);
            }
            std::cout << "\nYour message has been sent successfully to everyone, which you have choosen" << std::endl;
            break;
        }
        case 4: {
            system("cls");
            std::cout << "You have been logged out" << std::endl;
            if (SC == 1) {
                close(socket_file_descriptor);
            }
            else if (SC == 2) {
                close(socket_descriptor);
            }
            page1();
            break;
        }
        default: {
            std::cout << "Please, choose a number between 1 - 4" << std::endl;
            break;
        }
        }
    } while (choice2 != 4);
}



int main() {

	page1();
	
	return 0;
}