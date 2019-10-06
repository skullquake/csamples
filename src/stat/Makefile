CC=gcc
SRC=./src/a.c
BIN=./bin/a.out
CFLAGS=`pkg-config --cflags json-c`
LIBS=`pkg-config --libs json-c`
$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(BIN)
.phony:\
	run\
	clean
run: $(BIN)
	$(BIN)
clean:
	rm $(BIN)
