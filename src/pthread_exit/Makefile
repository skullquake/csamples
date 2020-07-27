CC=gcc
SRC=./src/a.c
BIN=./bin/a.out
LDFLAGS=-lpthread
CFLAGS=-Wall -Wextra
$(BIN): $(SRC)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(BIN)
.phony:\
	run\
	clean
run: $(BIN)
	$(BIN)
clean:
	rm $(BIN)
