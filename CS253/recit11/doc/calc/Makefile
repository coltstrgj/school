CXXFLAGS=-g -Wall -W -Werror -I.
LDFLAGS=
LIBS=-lm -lcurses -lefence

sources=$(wildcard *.cc fn/*/*.cc)

OBJS=${sources:.cc=.o}

calc:	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $@ $(LIBS)

$(OBJS): calc.h

tags:
	ctags *.h $(sources)

clean:
	-rm -f calc *.o */*/*.o
