CC=gcc
SRC=./src/a.c
BINOPT0=./bin/a_O0.out
BINOPT4=./bin/a_O4.out
CFLAGS=-Wall -Wextra
LDFLAGS=
all:$(BINOPT0) $(BINOPT4)
$(BINOPT0): $(SRC)
	@echo generating $(BINOPT0)
	@mkdir -p $(@D)
	@$(CC) -O0 $(CFLAGS) $(SRC) $(LDFLAGS) -o $(BINOPT0)
$(BINOPT4): $(SRC)
	@echo generating $(BINOPT4)
	@mkdir -p $(@D)
	@$(CC) -O4 $(CFLAGS) $(SRC) $(LDFLAGS) -o $(BINOPT4)
.phony:\
	run\
	clean
run: $(BINOPT0) $(BINOPT4)
	@echo With Optimization:
	@$(BINOPT4)
	@echo Without Optimization:
	@$(BINOPT0)
clean:
	@-rm $(BINOPT0) $(BINOPT4)
