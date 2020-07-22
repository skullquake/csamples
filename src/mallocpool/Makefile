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
	@-$(BIN) 32 128 1024
	@-$(BIN) 64 128 1024
	@-$(BIN) 128 128 1024
clean:
	@-rm $(BIN)
