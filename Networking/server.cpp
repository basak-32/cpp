#include<iostream>
#include<stdio.h>
#include<winsock2.h>
#include<ws2tcpip.h>
#include<unistd.h>

using namespace std;

struct sockaddr_in serverAddress, clientAddress;


int main(int argc, char const *argv[]) {

  // Initializing the WSA variables -->
  WSADATA ws;
  if (WSAStartup(MAKEWORD(2, 2), &ws) < 0) {
    cout << "WSA initialization failed!" << endl;
    return 1;
  } else
    cout << "WSA initialized successfully" << endl;
  


  // Initializing socket -->
  int socketVariable = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (socketVariable < 0) {
    cout << "The Socket not opened!" << endl;
    return 1;
  } else
    cout << "The Socket opened successfully" << endl;



  // Initializing the environment for socaddr structure -->
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(9000);
  // serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  memset(&(serverAddress.sin_zero), 0, 8);



  // Binding the Socket to address -->
  int bindVariable = 0;
  bindVariable = bind(socketVariable, (sockaddr*)&serverAddress, sizeof(sockaddr));

  if (bindVariable < 0) {
    cout << "Socket binding to address failed!" << endl;
    return 1;
  } else
    cout << "Socket binding to address done" << endl;



  // Listening to the requests -->
  int listenVariable = 0;
  listenVariable = listen(socketVariable, 10);

  if (listenVariable < 0) {
    cout << "Listening to clients Failed!" << endl;
    return 1;
  } else
    cout << "Started listening to clients" << endl;



  // Accept request from client -->
  struct sockaddr_storage client_address;    
  socklen_t client_len = sizeof(client_address);

  int newSocketVariable = 0;
  newSocketVariable = accept(socketVariable, (struct sockaddr*)&clientAddress, &client_len);

  if (newSocketVariable < 0) {
    cout << "Error accepting request" << endl;
    return 1;
  } else {
    cout << "Server got connection from " << inet_ntoa(clientAddress.sin_addr) << " port " << ntohs(clientAddress.sin_port) << endl;
  }



  while (1) {
    // Send and Receive -->
    int result;
    char recvbuf[512]{};
    
    // memset(&recvbuf, 0, 512);

    result = recv(newSocketVariable, recvbuf, 512, 0);
    if (result > 0)
      cout << "Bytes received: " << result << endl;

    if (recvbuf[0] == '0') {
      break;
    }

    cout << "From Client: ";
    int i = 0;
    while (recvbuf[i] != '\0')
      cout << recvbuf[i++];
    cout << endl;
    
    char sendbuf[512]{};
    cout << "Write your message: ";
    cin.getline(sendbuf, 512);

    int result2 = send(newSocketVariable, sendbuf, (int) strlen(sendbuf), 0);
    cout << "Bytes sent: " << result2 << endl;
  }



  close(newSocketVariable);
  close(socketVariable);

  return 0;
}