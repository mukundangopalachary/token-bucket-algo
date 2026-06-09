CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -Iinclude -g

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

TARGET = build/token_bucket_sim

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p build
	$(CC) $(OBJ) -o $(TARGET)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f src/*.o
	rm -rf build

rebuild: clean all

.PHONY: all run clean rebuild
