CC = g++
CFLAGS = -c
SOURCES =  main.cpp merge.cpp Test.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = codetask

all: $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
		$(CC) $(OBJECTS) -o $@

.cpp.o: *.h
	$(CC) $(CFLAGS) $< -o $@

clean :
	-rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean
