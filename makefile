CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=$(wildcard $(SRC)*.cpp) $(wildcard $(SRC)/*/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=gord
BUILD=build/
SRC=src/
RELEASE=release/
DEBUG=debug/

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(addprefix $(BUILD),$(notdir $(OBJECTS))) -o $(addprefix $(RELEASE),$(EXECUTABLE))

.cpp.o:
	$(CC) $(CFLAGS) $< -o $(addprefix $(BUILD),$(notdir $@))

.PHONY: clean

clean:
	rm -f $(addprefix $(RELEASE),$(EXECUTABLE))
	rm -f $(addprefix $(DEBUG),$(EXECUTABLE))
	rm -f $(wildcard $(BUILD)*.o)
