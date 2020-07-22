CC=gcc
SRC=./src/a.c
BIN=./bin/a.out
CFLAGS=-DNDEBUG
LDFLAGS=
$(BIN): $(SRC)
	@-echo compiling $(@D)
	@-mkdir -p $(@D)
	@-$(CC)\
		$(CFLAGS)\
		$(SRC)\
		$(LDFLAGS)\
		-o $(BIN)
.phony:\
	run\
	clean
run: $(BIN)
	@-echo executing $(@D)
	@-$(BIN)
clean:
	@-rm $(BIN)
