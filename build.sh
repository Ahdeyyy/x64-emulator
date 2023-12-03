#!/bin/bash

# Define directories
SRC_DIR="./src"
LIB_DIR="./src/libs"
INCLUDE_DIR="./src/libs/include"

# Define the output file
OUTPUT_FILE="bin/main"

# Find all .cpp files in the SRC_DIR
CPP_FILES=$(find $SRC_DIR -name "*.cpp")

# Compile and link the project
g++ -I$INCLUDE_DIR -L$LIB_DIR $CPP_FILES -o $OUTPUT_FILE