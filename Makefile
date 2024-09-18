##
## EPITECH PROJECT, 2024
## B-NWP-400-MPL-4-1-myftp-censured.censured
## File description:
## Makefile
##

CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = myftp

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

tests:
	make fclean
	make -j8
	valgrind ./$(TARGET) 1025 ./.test_directory

cs:
	make fclean
	~/coding-style.sh . .
	cat coding-style-reports.log
	rm -rf coding-style-reports.log
