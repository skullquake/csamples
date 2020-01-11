CC=gcc
CFLAGS=\
	-I./include
SRC=\
	./src/a.c\
	./src/getch.c
BIN=./bin/a.out
$(BIN): $(SRC)
	$(CC)\
		$(CFLAGS)\
		$(SRC)\
		-o $(BIN)
.phony:\
	run\
	clean
run: $(BIN)
	cat ./res/tst.txt|$(BIN)
clean:
	rm $(BIN)
