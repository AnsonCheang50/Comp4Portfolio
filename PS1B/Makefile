CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lboost_unit_test_framework
DEPS = FibLFSR.h
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

all: PhotoMagic

PhotoMagic: photoMagic.o FibLFSR.o
	$(CC) $(CFLAGS) -o PhotoMagic $^ $(LIBS) $(SFMLFLAGS)

clean:
	rm *.o PhotoMagic
