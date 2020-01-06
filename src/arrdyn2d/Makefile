CC=gcc
SRC=./src/a.c
BIN=./bin/a.out
$(BIN): $(SRC)
	$(CC) $(SRC) -o $(BIN)
.phony:\
	run\
	clean
run: $(BIN)
	$(BIN) 10 10
clean:
	rm $(BIN)
