CC=gcc
SANITIZE = -g -fsanitize=address
CFLAGS=-g -Wall -Wextra -Werror
DEPS = add_functions.h
OBJ = my_mastermind.o add_functions.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(SANITIZE)

my_mastermind: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(SANITIZE)


clean:
	rm -f $(OBJ)
	rm -f my_mastermind