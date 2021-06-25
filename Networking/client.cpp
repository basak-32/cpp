#include<iostream>
#include<winsock2.h>
#include<unistd.h>

using namespace std;

struct sockaddr_in srv;


int main(int argc, char const *argv[]) {
  // Initializing the WSA variables -->
  WSADATA ws;
  if (WSAStartup(MAKEWORD(2, 2), &ws) < 0) {
    cout << "WSA initialization failed!" << endl;
    return 1;
  } else
    cout << "WSA initialized successfully" << endl;


  // Initializing socket -->
  int socketId = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (socketId < 0) {
    cout << "The Socket not opened!" << endl;
    return 1;
  } else
    cout << "The Socket opened successfully" << endl;


  // Initializing the environment for socaddr structure -->
  srv.sin_family = AF_INET;
  srv.sin_port = htons(9000);
  srv.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(&(srv.sin_zero), 0, 8);


  // Connect -->
  int connectId = connect(socketId, (struct sockaddr*)&srv, sizeof(srv));

  if (connectId < 0) {
    cout << "Connect failed!" << endl;
    WSACleanup();
    return 1;
  } else {
    cout << "Connected to the server" << endl;
  }

  while (1) {  
    // Send -->

    // const char *sendbuf = "Hello, I'm Client";
    char recvbuf[512]{};
    char sendbuf[512]{};

    cout << "(Enter 0 to end the connection)" << endl;

    cout << "Write message: ";
    cin.getline(sendbuf, 512);

    int result = send(socketId, sendbuf, (int) strlen(sendbuf), 0);

    cout << "Bytes send: " << result << endl;

    if (sendbuf[0] == '0')
      break;

    
    // Receive -->
    result = recv(socketId, recvbuf, 512, 0);
    if (result > 0) {
      cout << "Bytes received: " << result << endl;

      if (recvbuf[0] == '0')
        break;

      cout << "From Server: ";
      int i = 0;
      while (recvbuf[i] != '\0')
        cout << recvbuf[i++];
      cout << endl;
    }
    else if (result == 0)
      cout << "Connection closed" << endl;
    else
      cout << "Received failed!" << endl;

  }
  

  close(socketId);

  return 0;
}