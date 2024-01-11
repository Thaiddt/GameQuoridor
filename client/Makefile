CC = g++
CFLAGS = -std=c++11 -Wall -g
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

CLIENT_SRCS = controller/LoginController.cpp model/User.cpp network/ClientNetwork.cpp view/LoginUI.cpp message/Message.cpp Client.cpp

CLIENT_OBJS = $(CLIENT_SRCS:.cpp=.o)

all: Client

Client: $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(SFML_LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(CLIENT_OBJS) Client
