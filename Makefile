CC=gcc
CFLAGS=-c -Wall -fpic
LDFLAGS=-shared
SOURCES=$(wildcard $(SRC)*.c) $(wildcard $(SRC)/*/*.c)
TESTS=$(wildcard $(TEST)*.c) $(wildcard $(TEST)/*/*.c)
CFLAGS_TESTS=-Wall
LDFLAGS_TESTS=
OBJECTS=$(SOURCES:.c=.o)
LIBNAME=libgord.so
BUILD=build/
SRC=src/
TEST=testing/
RELEASE=release/
DEBUG=debug/
MKDIR_P=mkdir -p
RM_DIR=rm -rf

all: $(SOURCES) MK_DIRS $(LIBNAME)

tests:
	$(CC) 

MK_DIRS:
	$(MKDIR_P) $(BUILD)
	$(MKDIR_P) $(RELEASE)

$(LIBNAME): $(OBJECTS)
	$(CC) $(LDFLAGS) $(addprefix $(BUILD),$(notdir $(OBJECTS))) -o $(addprefix $(RELEASE),$(LIBNAME))

.c.o:
	$(CC) $(CFLAGS) $< -o $(addprefix $(BUILD),$(notdir $@))

.PHONY: clean

clean:
	$(RM_DIR) $(BUILD)
	$(RM_DIR) $(RELEASE)
