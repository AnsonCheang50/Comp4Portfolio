CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lboost_unit_test_framework
DEPS = Triangle.h
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

all: TFractal

TFractal: TFractal.o Triangle.o
	$(CC) $(CFLAGS) -o TFractal $^  $(LIBS) $(SFMLFLAGS)
	cpplint --filter=-runtime/references *.cpp *.h

clean:
	rm *.o TFractal