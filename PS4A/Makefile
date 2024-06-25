CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lboost_unit_test_framework
DEPS = CircularBuffer.h
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

all: test

test: test.o CircularBuffer.o
	$(CC) $(CFLAGS) -o test $^  $(LIBS) $(SFMLFLAGS)
	cpplint --filter=-runtime/references *.cpp *.h

clean:
	rm *.o test