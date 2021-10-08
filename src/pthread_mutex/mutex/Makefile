CC=gcc
SRC=./src/a.c
BIN=./bin/a.out
CFLAGS=-Wall
LDFLAGS=-lpthread
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
