CXXFLAGS=-g -Wall -Wextra -ansi -pedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -Wctor-dtor-privacy -Wold-style-cast -D_GLIBCXX_DEBUG -fno-diagnostics-show-option

all:	Calendar

Calendar:	
	g++ $(CXXFLAGS) main.cc Calendar.cc CalendarBase.cc  `pkg-config gtkmm-3.0 --cflags --libs`
clean:
	rm Calendar

