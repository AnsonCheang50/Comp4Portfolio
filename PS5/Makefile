CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lboost_unit_test_framework
DEPS = EDistance.h
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

all: EDistance

EDistance: main.o EDistance.o
	$(CC) -g $(CFLAGS) -o EDistance $^  $(LIBS) $(SFMLFLAGS)
	cpplint --filter=-runtime/references *.cpp *.h

clean:
	rm *.o EDistance