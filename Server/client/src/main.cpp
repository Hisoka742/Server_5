#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    struct sockaddr_in server_address;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);

    // Convert IP address from string to structure
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return 1;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        return 1;
    }

    // Send request to server
    const char* message = "Hello, Server!";
    send(sockfd, message, strlen(message), 0);
    std::cout << "Message sent to server" << std::endl;

    close(sockfd);
    return 0;
}
