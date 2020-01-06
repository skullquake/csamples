CC=gcc
SRC=./src/a.c
BIN=./bin/a.out
$(BIN): $(SRC)
	$(CC) $(SRC) -o $(BIN)
.phony:\
	run\
	clean
run: $(BIN)
	$(BIN) 8 8 8 
clean:
	rm $(BIN)
