#!/bin/bash

# Usage: ./make.sh MyProject [-p] [additional_files]
# -p: Gives the permission to run

PROGRAM_NAME="$1"
GIVE_CHMOD_PERMISSION=false
BINARIES_PATH="$HOME/packages/bin"
SOURCE_DIR="$PROGRAM_NAME"
OUTPUT_BINARY="$PROGRAM_NAME.bin"

# Handle optional -p flag
if [ "$2" = "-p" ]; then
  GIVE_CHMOD_PERMISSION=true
  ADDITIONAL_FILES="$3"
else
  ADDITIONAL_FILES="$2"
fi

# Ensure the source file exists
if [ ! -f "$SOURCE_DIR/main.c" ]; then
  echo "Error: $SOURCE_DIR/main.c not found."
  exit 1
fi

# Compile the program
clang "$SOURCE_DIR/main.c" $ADDITIONAL_FILES -lncurses
mv a.out $OUTPUT_BINARY
if [ $? -ne 0 ]; then
  echo "Compilation failed."
  exit 1
fi

# Create target path if it doesn't exist
mkdir -p "$BINARIES_PATH"

# Copy the compiled binary to the destination path
cp "$OUTPUT_BINARY" "$BINARIES_PATH/$PROGRAM_NAME"

rm $OUTPUT_BINARY

# Give binary chmod permission if -p flag was used
if $GIVE_CHMOD_PERMISSION; then
  chmod +x "$BINARIES_PATH/$PROGRAM_NAME"
fi

# Run the program
"$PROGRAM_NAME"