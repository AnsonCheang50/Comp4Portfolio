CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lboost_unit_test_framework -lboost_date_time -lboost_regex
DEPS = RandWriter.h
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

all: ps7

ps7: KronosTime.o
	$(CC) -g $(CFLAGS) -o ps7 $^  $(LIBS) $(SFMLFLAGS)
	cpplint --filter=-runtime/references *.cpp

clean:
	rm *.o ps7