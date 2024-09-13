
#include <string>

class ServerInterface {
public:
    virtual ~ServerInterface() = default;
    virtual std::string HandleRequest(const std::string& request) = 0;
};

// MockServer.h

#include <gmock/gmock.h>


class MockServer : public ServerInterface {
public:
    MOCK_METHOD1(HandleRequest, std::string(const std::string& request));
};
// Client.h

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define SERV_IP "127.0.0.1"
class Client {
public:
    Client(const std::string& server_ip, int server_port);
    ~Client();
    std::string SendMessage(const std::string& message);

private:
    int sockfd;
    sockaddr_in server_addr;
};
// Client.cpp

#include <unistd.h>
#include <cstring>
#include <iostream>

Client::Client(const std::string& server_ip, int server_port) {
    std::cout<<"client start"<<std::endl;
}

Client::~Client() {
}

std::string Client::SendMessage(const std::string& message) {
    send(sockfd, message.c_str(), message.size(), 0);

    char buffer[1024] = {0};
    recv(sockfd, buffer, sizeof(buffer), 0);

    return std::string(buffer);
}
// ServerTest.cpp
#include <gtest/gtest.h>
#include <gmock/gmock.h>


using ::testing::Return;

class MockSocketServer {
public:
    MockSocketServer(MockServer& mock_server) : mock_server_(mock_server) {}

    void Start() {
        // 模拟服务端的行为
        std::string request = "Hello";

        std::string response = mock_server_.HandleRequest(request);
        // 处理客户端请求并返回响应
        // 在实际应用中，这里会涉及到 socket 监听、接收和发送数据
        // 在测试中，我们使用 Mock 对象来模拟这些操作
    }

private:
    MockServer& mock_server_;
};

TEST(ClientTest, SendMessage) {
    MockServer mock_server;
    std::string expected_response = "World";

    // 设置期望并指定返回值
    EXPECT_CALL(mock_server, HandleRequest("Hello"))
        .WillOnce(Return(expected_response));

    MockSocketServer mock_socket_server(mock_server);
    mock_socket_server.Start();

    // 创建客户端并发送消息
    Client client("127.0.0.1", 8080);
    std::string response = client.SendMessage("Hello");

    EXPECT_EQ(response, expected_response);
}
