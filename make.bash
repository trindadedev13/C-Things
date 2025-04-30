#!/bin/bash

# Usage: ./make.sh MyProject [-p] [-i]
# -p: Gives the permission to run
# -i: Installs to $BINARIES_PATH (default is $HOME)

PROGRAM_NAME="$1"
GIVE_CHMOD_PERMISSION=false
INSTALL_TO_BINARIES=false
BINARIES_PATH="$HOME/packages/bin"
SOURCE_DIR="$PROGRAM_NAME"
OUTPUT_BINARY="$PROGRAM_NAME.bin"

# Handle optional flags
shift
while [[ "$#" -gt 0 ]]; do
  case "$1" in
    -p) GIVE_CHMOD_PERMISSION=true ;;
    -i) INSTALL_TO_BINARIES=true ;;
    *) echo "Unknown option: $1" ; exit 1 ;;
  esac
  shift
done

# Ensure the source directory contains at least one .c file
if ! ls "$SOURCE_DIR"/*.c &> /dev/null; then
  echo "Error: No .c files found in $SOURCE_DIR."
  exit 1
fi

# Compile the program using all .c files in the source directory
clang "$SOURCE_DIR"/*.c -lncurses
if [ $? -ne 0 ]; then
  echo "Compilation failed."
  exit 1
fi

mv a.out "$OUTPUT_BINARY"

# Determine destination path
DEST_PATH="$HOME"
if $INSTALL_TO_BINARIES; then
  mkdir -p "$BINARIES_PATH"
  DEST_PATH="$BINARIES_PATH"
fi

# Copy the compiled binary
cp "$OUTPUT_BINARY" "$DEST_PATH/$PROGRAM_NAME"
rm "$OUTPUT_BINARY"

# Apply chmod if requested
if $GIVE_CHMOD_PERMISSION; then
  chmod +x "$DEST_PATH/$PROGRAM_NAME"
fi

# Run the program
cd "$DEST_PATH"
"./$PROGRAM_NAME"