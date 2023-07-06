#pragma once
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
using namespace std;



#define MESSAGE_BUFFER 4096 // ������������ ������ ������ ��� ������ � ��������
#define PORT 7777 // ����� �����, ������� ����� ������������ ��� ������ � �������� 


char buffer[MESSAGE_BUFFER];
char SendMessage[MESSAGE_BUFFER];
int socket_file_descriptor, message_size;
socklen_t length;
const char* end_string = "end";
struct sockaddr_in serveraddress, client;

void processRequest() {
    // �������� UDP ����� 
    socket_file_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
    serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);
    // ������� ���� ��� ����������
    serveraddress.sin_port = htons(PORT);
    // ���������� IPv4
    serveraddress.sin_family = AF_INET;
    // �������� ����� 
    bind(socket_file_descriptor, (struct sockaddr*)&serveraddress, sizeof(serveraddress));
}