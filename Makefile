CC=gcc
CFLAGS=-c -g -Wall
LDFLAGS= -g
SOURCES=daytimeserver.c libs/stringutility.c libs/portutility.c 
OBJECTS=$(SOURCES:.cpp=.o)
	EXECUTABLE=daytimeserver

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(OBJECTS) 
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o
