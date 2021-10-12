#CC=x86_64-linux-gnu-gcc-9
#CC=x86_64-w64-mingw32-gcc-9.3-posix
ifeq ($(CC),)
	CC=x86_64-linux-gnu-gcc-9
endif
SRC=./src/a.c
COMPILERVERSION=$(shell $(CC) -dumpversion)
TGT_MACHINE=$(shell $(CC) -dumpmachine)
LIBNAM=$(shell basename `pwd`)
CFLAGS+=-Wall -I./src
LDFLAGS+=-shared -fpic
ifneq (,$(findstring mingw,$(TGT_MACHINE)))
	LDFLAGS+=-Wl,--export-all-symbols
	ifneq (,$(findstring posix,$(TGT_MACHINE)))
	else
	endif
else
	LDFLAGS+=-Wl,--export-dynamic 
endif
ifneq (,$(findstring mingw,$(TGT_MACHINE)))
	DSOEXT=.dll
else
	DSOEXT=.so
endif
BINDIR=./bin/$(TGT_MACHINE)
LIB=$(BINDIR)/$(LIBNAM)$(DSOEXT)
SRC:=$(shell find $(SRCDIR) -name '*.c')
OBJS:=$(addprefix $(BINDIR)/,$(SRC:%.c=%.o))
CFLAGS=-I./include
all:\
	$(LIB)
$(LIB):$(OBJS)
	@printf "generating $@...\n"
	@mkdir -p $(@D)
	@$(CC)\
		$(CFLAGS)\
		$(OBJS)\
		$(LDFLAGS)\
		-o $(LIB)
$(BINDIR)/%.o: %.c
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
	lsvar
clean:
	@rm -r ./bin
run:
	$(BIN)


