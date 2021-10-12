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
LIB=./bin/$(TGT_MACHINE)/$(LIBNAM)$(DSOEXT)
all:$(LIB)
$(LIB):$(SRC) $(LIBAPP)
	@-mkdir -p ./bin/$(TGT_MACHINE)
	@$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(LIB)
.phony:clean
clean:
	@-echo removing $(LIB)
	@rm $(LIB)
