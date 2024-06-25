CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lboost_unit_test_framework
DEPS = CelestialBody.h Universe.h
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

all: NBody

NBody: main.o CelestialBody.o Universe.o
	$(CC) $(CFLAGS) -o NBody $^  $(LIBS) $(SFMLFLAGS)

clean:
	rm *.o NBody