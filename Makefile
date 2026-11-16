# Default targets
.PHONY: all build run clean


# Compilers
CC := clang
AR ?= arduino-cli


# Compiler flags
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic -Werror -O0 -g
CPPFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -Werror -O0 -g


# Directories
BUILD_DIR := build
SOURCE_DIR := src


# Native source files
C_SOURCES := $(wildcard src/*.c)


build: ${SOURCE_DIR}/main.c
	@${CC} ${CFLAGS} ${SOURCE_DIR}/main.c -o ${BUILD_DIR}/main

run: ${BUILD_DIR}/main
	@${BUILD_DIR}/main

clean:
	rm -rf "$(BUILD_DIR)"
