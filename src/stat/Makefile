CC=gcc
SRC=./src/a.c
BIN=./bin/a.out
$(BIN): $(SRC)
	@mkdir -p $(@D)
	$(CC) $(SRC) -o $(BIN)
.phony:\
	run\
	clean
run: $(BIN)
	$(BIN)
clean:
	rm $(BIN)
