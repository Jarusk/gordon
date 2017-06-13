CC=clang
CFLAGS=-pipe -c -Wall -fpic -O2
LDFLAGS=-shared -nostdlib
SOURCES=$(wildcard $(SRC)*.c) $(wildcard $(SRC)/*/*.c)
TESTS=$(wildcard $(TEST)*.c) $(wildcard $(TEST)/*/*.c)
OBJECTS=$(SOURCES:.c=.o)
LIBNAME=libgord.so
BUILD=/tmp/gordon_build/
SRC=src/
TEST=testing/
RELEASE=release/
MKDIR_P=mkdir -p
RM_DIR=rm -rf

all: $(SOURCES) MK_DIRS $(LIBNAME)

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
