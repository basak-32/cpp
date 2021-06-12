#include<iostream>
#include<stdio.h>
#include<winsock2.h>
#include<ws2tcpip.h>
#include<unistd.h>

using namespace std;

struct sockaddr_in serverAddress, clientAddress;

#define DEFAULT_BUFLEN 512

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


  // // Send -->
  // int result = send(newSocketVariable, "Hello, world!\n", 13, 0);
  // cout << "Bytes sent: " << result << endl;


  // // Read -->
  // char buffer[256];
  // memset(&buffer, 0, 256);

  // result = read(newSocketVariable, &buffer, 255);
  // cout << "Bytes received: " << result << endl;


  //   cout << "Here is the message from socket: " << buffer << endl;


  int result;
  char recvbuf[DEFAULT_BUFLEN];
  int recvbuflen = DEFAULT_BUFLEN;
  memset(&recvbuf, 0, recvbuflen);

  result = recv(newSocketVariable, recvbuf, recvbuflen, 0);
  if (result > 0)
    cout << "Bytes received: " << result << endl;

  int i = 0;
  while (recvbuf[i] != '\0')
    cout << recvbuf[i++];

  int result2 = send(newSocketVariable, recvbuf, result, 0);
  cout << "Bytes sent: " << result2 << endl;



  close(newSocketVariable);
  close(socketVariable);

  return 0;
}