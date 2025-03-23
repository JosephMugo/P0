CC = g++
CFLAGS = -g -Wall -std=c++11
OBJS = main.o buildTree.o traversals.o queue.o node.o
TARGET = P0

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
