OS=$(shell $(CXX) -dumpmachine)
ifneq (,$(findstring mingw,$(OS)))
SOEXT?=dll
BINEXT?=.exe
else
SOEXT?=so
BINEXT?=
endif
ifeq ($(PREFIX),)
PREFIX := /usr/local
endif
CC=gcc
CXX=g++
AR=ar
BUILDDIR=./bin/build
BINNAM=daemon
BIN=./bin/$(BINNAM)$(BINEXT)
SRCDIR=src
SRC:=$(shell find $(SRCDIR) -name '*.c')
OBJS:=$(addprefix $(BUILDDIR)/,$(SRC:%.c=%.o))
CFLAGS=\
	-I./include
LDFLAGS=\
	-llog
all:\
	$(BIN)
$(BIN):$(OBJS)
	@$(CC)\
		$(CFLAGS)\
		$(OBJS)\
		$(LDFLAGS)\
		-o $(BIN)
$(BUILDDIR)/%.o: %.c
	@printf "generating $@...\n"
	@mkdir -p $(@D)
	@$(CC)\
		$(CFLAGS)\
		-c $<\
		$(LDFLAGS)\
		-o $@
.phony:\
	run\
	clean\
	catlog
clean:
	@rm -r ./bin
run: $(BIN)
	$(BIN)
catlog:
	logcat -s 'syslog:*'
