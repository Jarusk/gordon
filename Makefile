# THE NEXT FOUR VARS ARE OVERRIDDEN BY config.mak
CC=
CFLAGS=
LDFLAGS=
ARCH=

#Pull in our generated config.mak vars from ./configure
include config.mak

ARCHINCLUDE=arch/$(ARCH)/
SOURCES=$(wildcard $(SRC)*.c) $(wildcard $(SRC)*/*.c)
OBJECTS=$(SOURCES:.c=.o)
LIBNAME=libgord.so
BUILD=/tmp/gordon_build/
SRC=src/
TEST=testing/
RELEASE=release/
MKDIR_P=mkdir -p
RM_DIR=rm -rf

all: config.mak $(SOURCES) MK_DIRS $(LIBNAME)

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
	#if [ -f config.mak ]; then rm config.mak; fi
