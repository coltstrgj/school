## Variable that points to SystemC installation path
SYSTEMC = /usr/local/systemc-2.2.0
TARGET_ARCH = linux64#(or linux for 32 bit machines)
CC = g++
INCDIR = -I. -I.. -I$(SYSTEMC)/include
LIBDIR = -L. -L.. -L$(SYSTEMC)/lib-$(TARGET_ARCH)
LIBS = -lsystemc -lm $(EXTRA_LIBS)
## Change the OBJ variable to reflect your source files
MODULE = simple_fifo
OBJS = simple_fifo.o
EXE = $(MODULE).x
.SUFFIXES: .cc .cpp .o .x

$(EXE): $(OBJS) $(SYSTEMC)/lib-$(TARGET_ARCH)/libsystemc.a
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(OBJS) $(LIBS) 2>&1 | c++filt

.cpp.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<

.cc.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<

clean::
	rm -f $(OBJS) *~ $(EXE) core

ultraclean: clean
	rm -f Makefile.deps

Makefile.deps:
#	$(CC) $(CFLAGS) $(INCDIR) -M $(SRCS) >> Makefile.deps

#include Makefile.deps
