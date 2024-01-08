CXX = g++
CXXFLAGS = -std=c++11
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = signup.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = signup

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(SFML_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
