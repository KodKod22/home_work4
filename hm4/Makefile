FLAGS=-Wall -pedantic-errors -std=c99
RDB_DIR=../
CC=gcc

all: test1 test2

test1: main.c $(RDB_DIR)/*.c
	$(CC) $(FLAGS) -I$(RDB_DIR) main.c $(RDB_DIR)/*.c -L$(RDB_DIR) -lprog2 -o $@.exe
	./$@.exe > $@.out 2> $@.err
 
test2: main.c $(RDB_DIR)/*.c
	$(CC) $(FLAGS) -I$(RDB_DIR) main.c $(RDB_DIR)/*.c -L$(RDB_DIR) -lprog2 -o $@.exe
	./$@.exe > $@.out 2> $@.err
 
clean:
	rm -f *.o *.exe test1 test2

.PHONY: test1 test2 g_test clean
