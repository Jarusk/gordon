CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=$(wildcard $(SRC)*.cpp)
OBJECTS=$(subst $(SRC),$(BUILD),$(SOURCES:.cpp=.o))
EXECUTABLE=hello
BUILD=build/
SRC=src/
RELEASE=release/
DEBUG=debug/

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
