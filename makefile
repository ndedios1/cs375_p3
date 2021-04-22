CC = g++

all: submission

submission:	submission.o	Item.o
	$(CC) -g -o submission submission.o Item.o

submission.o:	submission.cpp
	$(CC) -Wall -c submission.cpp

Item.o:		Item.cpp
	$(CC) -Wall -c Item.cpp

clean:
	-rm *.o	submission
