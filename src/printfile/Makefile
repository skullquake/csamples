CC=gcc
SRC=./src/a.c
BIN=./bin/a.out
$(BIN): $(SRC)
	$(CC) $(SRC) -o $(BIN)
.phony:\
	run\
	clean
run:
	$(BIN) ./res/a.txt
clean:
	rm $(BIN)
