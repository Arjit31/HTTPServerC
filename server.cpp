#include <bits/stdc++.h>
#include <winsock2.h>

int main(){
    //Creating the Server Socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    //Defining Server Address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    //Binding the Server Socket to the Server Address
    bind(serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress));
    listen(serverSocket, SOMAXCONN);

    //Accepting the Client Socket
    int clientSocket = accept(serverSocket, nullptr, nullptr);

    //Receiving the Message from the Client
    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    std::cout << "Message from client: " << buffer << std::endl;

    //Closing the Server Socket
    closesocket(serverSocket);

    return 0;
}