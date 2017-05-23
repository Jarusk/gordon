CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=$(wildcard $(SRC)*.c) $(wildcard $(SRC)/*/*.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=gord
BUILD=build/
SRC=src/
RELEASE=release/
DEBUG=debug/
MKDIR_P=mkdir -p
RM_DIR=rm -rf

all: $(SOURCES) MK_DIRS $(EXECUTABLE)

MK_DIRS:
	$(MKDIR_P) $(BUILD)
	$(MKDIR_P) $(RELEASE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(addprefix $(BUILD),$(notdir $(OBJECTS))) -o $(addprefix $(RELEASE),$(EXECUTABLE))

.c.o:
	$(CC) $(CFLAGS) $< -o $(addprefix $(BUILD),$(notdir $@))

.PHONY: clean

clean:
	$(RM_DIR) $(BUILD)
	$(RM_DIR) $(RELEASE)
