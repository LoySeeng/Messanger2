#pragma once
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <sys/socket.h> // Библиотека для работы с сокетами
#include <arpa/inet.h>

using namespace std;


// Максимальный размер буфера для приема и передачи
#define MESSAGE_BUFFER 4096
#define PORT 7777 // номер порта, который будем использовать для приема и передачи 


char buffer[MESSAGE_BUFFER];
char SendMessage[MESSAGE_BUFFER];

int socket_descriptor;
struct sockaddr_in serveraddress;

void sendRequest() {
    // Укажем адрес сервера
    serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    // Зададим номер порта для соединения с сервером
    serveraddress.sin_port = htons(PORT);
    // Используем IPv4
    serveraddress.sin_family = AF_INET;
    // Создадим сокет 
    socket_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
    // Установим соединение с сервером
    if (connect(socket_descriptor, (struct sockaddr*)&serveraddress, sizeof(serveraddress)) < 0) {
        cout << endl << " Something went wrong Connection Failed" << endl;
        exit(1);
    }
}

