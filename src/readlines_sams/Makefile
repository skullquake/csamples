CC=gcc
SRC=./src/a.c
BIN=./bin/a.out
$(BIN): $(SRC)
	@$(CC)\
		$(SRC)\
		-o $(BIN)
.phony:\
	run\
	clean
run: $(BIN)
	@$(BIN)
test0: $(BIN)
	printf "dog\napple\nzoo\nprogram\nmerry\n\n"|$(BIN)
test1: $(BIN)
	@bash -c 'for i in `seq 0 1 512`;do printf "$$RANDOM\n";done'|$(BIN)
clean:
	@rm $(BIN)
