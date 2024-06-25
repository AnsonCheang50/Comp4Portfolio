CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lboost_unit_test_framework
DEPS = CircularBuffer.h StringSound.h
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

all: KSGuitarSim

KSGuitarSim: KSGuitarSim.o CircularBuffer.o StringSound.o
	$(CC) -g $(CFLAGS) -o KSGuitarSim $^  $(LIBS) $(SFMLFLAGS)
	cpplint --filter=-runtime/references *.cpp *.h

clean:
	rm *.o KSGuitarSim