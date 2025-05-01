# Makefile for building and installing a C program

# Usage:
# make PROGRAM=MyProject [CHMOD=true] [INSTALL=true]

PROGRAM ?= MyProject
SOURCE_DIR := $(PROGRAM)
OUTPUT_BINARY := $(PROGRAM).bin
BINARIES_PATH := $(HOME)/packages/bin
DEST_PATH := $(if $(INSTALL),$(BINARIES_PATH),$(HOME))

CFLAGS := -lncurses -lSDL2 -lSDL2_mixer
SRC_FILES := $(wildcard $(SOURCE_DIR)/*.c)

.PHONY: all install clean run

all: check_sources compile install chmod run

check_sources:
	@if [ -z "$(SRC_FILES)" ]; then \
		echo "Error: No .c files found in $(SOURCE_DIR)."; \
		exit 1; \
	fi

compile:
	clang $(SRC_FILES) $(CFLAGS) -o $(OUTPUT_BINARY)

install:
	@mkdir -p $(DEST_PATH)
	cp $(OUTPUT_BINARY) $(DEST_PATH)/$(PROGRAM)
	rm -f $(OUTPUT_BINARY)

chmod:
ifneq ($(CHMOD),)
	chmod +x $(DEST_PATH)/$(PROGRAM)
endif

run:
	cd $(DEST_PATH) && ./$(PROGRAM)

clean:
	rm -f $(PROGRAM) $(OUTPUT_BINARY)