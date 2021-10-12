CC=gcc
CFLAGS=-Wall
LDFLAGS=
SRC=./src/a.c
BIN=./bin/a.out
$(BIN):$(SRC)
	@$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(BIN)
run:$(BIN)
	@$(BIN)
.phony:clean
clean:
	@rm $(BIN)
