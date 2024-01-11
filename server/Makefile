CC = g++
CFLAGS = -std=c++11 -Wall -g
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

SERVER_SRCS = network/ServerNetwork.cpp message/Message.cpp Server.cpp

SERVER_OBJS = $(SERVER_SRCS:.cpp=.o)

all: Client

Client: $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(SFML_LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(SERVER_OBJS) Server