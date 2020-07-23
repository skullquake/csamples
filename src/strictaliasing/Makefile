CC=gcc
SRC=./src/a.c
BINOPT0=./bin/a_O0.out
BINOPT1=./bin/a_O1.out
BINOPT2=./bin/a_O2.out
BINOPT3=./bin/a_O3.out
BINOPT4=./bin/a_O4.out
CFLAGS=-Wall -Wextra
LDFLAGS=
all:$(BINOPT0) $(BINOPT1) $(BINOPT2) $(BINOPT3) $(BINOPT4)
$(BINOPT0): $(SRC)
	@echo generating $(BINOPT0)
	@mkdir -p $(@D)
	@$(CC) -O0 $(CFLAGS) $(SRC) $(LDFLAGS) -o $(BINOPT0)
$(BINOPT1): $(SRC)
	@echo generating $(BINOPT1)
	@mkdir -p $(@D)
	@$(CC) -O1 $(CFLAGS) $(SRC) $(LDFLAGS) -o $(BINOPT1)
$(BINOPT2): $(SRC)
	@echo generating $(BINOPT2)
	@mkdir -p $(@D)
	@$(CC) -O2 $(CFLAGS) $(SRC) $(LDFLAGS) -o $(BINOPT2)
$(BINOPT3): $(SRC)
	@echo generating $(BINOPT3)
	@mkdir -p $(@D)
	@$(CC) -O3 $(CFLAGS) $(SRC) $(LDFLAGS) -o $(BINOPT3)
$(BINOPT4): $(SRC)
	@echo generating $(BINOPT4)
	@mkdir -p $(@D)
	@$(CC) -O4 $(CFLAGS) $(SRC) $(LDFLAGS) -o $(BINOPT4)
.phony:\
	run\
	clean
run: $(BINOPT0) $(BINOPT2)
	@echo Optimiaztion Level 0:
	@$(BINOPT0)
	@echo Optimiaztion Level 1:
	@$(BINOPT1)
	@echo Optimiaztion Level 2:
	@$(BINOPT2)
	@echo Optimiaztion Level 3:
	@$(BINOPT3)
	@echo Optimiaztion Level 4:
	@$(BINOPT4)
clean:
	@-rm $(BINOPT0) $(BINOPT1) $(BINOPT2) $(BINOPT3) $(BINOPT4)
