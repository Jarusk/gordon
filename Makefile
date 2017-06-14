CC=gcc
CFLAGS=-pipe -c -Wall -fpic -O2 -nostdinc
LDFLAGS=-shared -nostdlib -nostdinc
ARCH=x86_64
ARCHINCLUDE=arch/$(ARCH)/
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
	$(CC) $(LDFLAGS) -I$(ARCHINCLUDE) -Iinclude/ $(addprefix $(BUILD),$(notdir $(OBJECTS))) -o $(addprefix $(RELEASE),$(LIBNAME))

.c.o:
	$(CC) $(CFLAGS) -I$(ARCHINCLUDE) -Iinclude/ $< -o $(addprefix $(BUILD),$(notdir $@))

.PHONY: clean

clean:
	$(RM_DIR) $(BUILD)
	$(RM_DIR) $(RELEASE)
