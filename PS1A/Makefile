CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lboost_unit_test_framework
DEPS = FibLFSR.h

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

all: ps1a

ps1a: test.o FibLFSR.o
	$(CC) $(CFLAGS) -o ps1a $^ $(LIBS)

clean:
	rm *.o ps1a
