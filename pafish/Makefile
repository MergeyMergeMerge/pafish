
CC        = i686-w64-mingw32-gcc
LINK      = i686-w64-mingw32-gcc
WINDRES   = i686-w64-mingw32-windres
OBJ       = Objects/MingW/main.o Objects/MingW/common.o Objects/MingW/utils.o Objects/MingW/debuggers.o Objects/MingW/sandboxie.o \
	    Objects/MingW/vbox.o Objects/MingW/gensandbox.o Objects/MingW/wine.o Objects/MingW/vmware.o \
	    Objects/MingW/qemu.o Objects/MingW/hooks.o Objects/MingW/cpu.o Objects/MingW/cuckoo.o Objects/MingW/bochs.o \
	    Objects/MingW/rtt.o Objects/MingW/spotlesssand.o Objects/MingW/pafish_private.res
LINKOBJ   = $(OBJ)
LIBS      = -lwsock32 -liphlpapi -lsetupapi -lmpr -lole32 -lwbemuuid -loleaut32 -lws2_32 -s
INCS      =
BIN       = Output/MingW/pafish.exe
CFLAGS    = $(INCS) -Wall -Wextra -Wpedantic -O0

all: $(BIN)

clean:
	rm -f Objects/MingW/*.o
	rm -f Objects/MingW/*.res
	rm -f Output/MingW/*.exe

$(BIN): $(OBJ)
	$(LINK) $(LINKOBJ) -o "$(BIN)" $(LIBS)

Objects/MingW/main.o: $(GLOBALDEPS) main.c
	$(CC) -c main.c -o Objects/MingW/main.o $(CFLAGS)

Objects/MingW/common.o: $(GLOBALDEPS) common.c
	$(CC) -c common.c -o Objects/MingW/common.o $(CFLAGS)

Objects/MingW/utils.o: $(GLOBALDEPS) utils.c
	$(CC) -c utils.c -o Objects/MingW/utils.o $(CFLAGS)

Objects/MingW/debuggers.o: $(GLOBALDEPS) debuggers.c
	$(CC) -c debuggers.c -o Objects/MingW/debuggers.o $(CFLAGS)

Objects/MingW/sandboxie.o: $(GLOBALDEPS) sandboxie.c
	$(CC) -c sandboxie.c -o Objects/MingW/sandboxie.o $(CFLAGS)

Objects/MingW/vbox.o: $(GLOBALDEPS) vbox.c
	$(CC) -c vbox.c -o Objects/MingW/vbox.o $(CFLAGS)

Objects/MingW/gensandbox.o: $(GLOBALDEPS) gensandbox.c
	$(CC) -c gensandbox.c -o Objects/MingW/gensandbox.o $(CFLAGS)

Objects/MingW/wine.o: $(GLOBALDEPS) wine.c
	$(CC) -c wine.c -o Objects/MingW/wine.o $(CFLAGS)

Objects/MingW/vmware.o: $(GLOBALDEPS) vmware.c
	$(CC) -c vmware.c -o Objects/MingW/vmware.o $(CFLAGS)

Objects/MingW/qemu.o: $(GLOBALDEPS) qemu.c
	$(CC) -c qemu.c -o Objects/MingW/qemu.o $(CFLAGS)

Objects/MingW/hooks.o: $(GLOBALDEPS) hooks.c
	$(CC) -c hooks.c -o Objects/MingW/hooks.o $(CFLAGS)

Objects/MingW/cpu.o: $(GLOBALDEPS) cpu.c
	$(CC) -c cpu.c -o Objects/MingW/cpu.o $(CFLAGS)

Objects/MingW/cuckoo.o: $(GLOBALDEPS) cuckoo.c
	$(CC) -c cuckoo.c -o Objects/MingW/cuckoo.o $(CFLAGS)

Objects/MingW/bochs.o: $(GLOBALDEPS) bochs.c
	$(CC) -c bochs.c -o Objects/MingW/bochs.o $(CFLAGS)

Objects/MingW/rtt.o: $(GLOBALDEPS) rtt.c
	$(CC) -c rtt.c -o Objects/MingW/rtt.o $(CFLAGS)

Objects/MingW/spotlesssand.o: $(GLOBALDEPS) spotlesssand.c
	$(CC) -c spotlesssand.c -o Objects/MingW/spotlesssand.o $(CLFLAGS)

Objects/MingW/pafish_private.res: Objects/MingW/pafish_private.rc
	$(WINDRES) Objects/MingW/pafish_private.rc --input-format=rc -o Objects/MingW/pafish_private.res -O coff
