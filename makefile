CC = g++

all: submission

submission:	submission.o
	$(CC) -g -o submission submission.o

submission.o:	submission.cpp
	$(CC) -Wall -c submission.cpp

clean:
	-rm *.o	submission
