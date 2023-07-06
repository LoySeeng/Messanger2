#pragma once
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <sys/socket.h> // ���������� ��� ������ � ��������
#include <arpa/inet.h>

using namespace std;


// ������������ ������ ������ ��� ������ � ��������
#define MESSAGE_BUFFER 4096
#define PORT 7777 // ����� �����, ������� ����� ������������ ��� ������ � �������� 


char buffer[MESSAGE_BUFFER];
char SendMessage[MESSAGE_BUFFER];

int socket_descriptor;
struct sockaddr_in serveraddress;

void sendRequest() {
    // ������ ����� �������
    serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    // ������� ����� ����� ��� ���������� � ��������
    serveraddress.sin_port = htons(PORT);
    // ���������� IPv4
    serveraddress.sin_family = AF_INET;
    // �������� ����� 
    socket_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
    // ��������� ���������� � ��������
    if (connect(socket_descriptor, (struct sockaddr*)&serveraddress, sizeof(serveraddress)) < 0) {
        cout << endl << " Something went wrong Connection Failed" << endl;
        exit(1);
    }
}

