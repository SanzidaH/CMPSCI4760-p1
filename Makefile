#make file - this is a comment section:
#all:    #target name
#       gcc simplechain.c -o simplechain

CC = gcc
CFLAGS = -g
TARGET1 = chain
OBJS1 = simplechain.c

.SUFFIXES: .c .o

all:       	
	$(CC) $(OBJS1) -o $(TARGET1)

#.PHONY: clean

clean:
	/bin/rm -f *.o $(TARGET1)
 
