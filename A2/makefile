CC = gcc
CFLAGS = -Wall -g
LIB = -Iinclude

all: n1 n2 n3 n4 n5 n6 n7

n1:
	$(CC) $(CFLAGS) $(LIBS) -c src/n1.c -o obj/n1.o
	$(CC) -o ./node1 obj/n1.o
n2:
	$(CC) $(CFLAGS) $(LIB) -c src/n2.c -o obj/n2.o
	$(CC) -o ./node2 obj/n2.o
n3:
	$(CC) $(CFLAGS) $(LIB) -c src/n3.c -o obj/n3.o
	$(CC) -o ./node3 obj/n3.o
n4:
	$(CC) $(CFLAGS) $(LIB) -c src/n4.c -o obj/n4.o
	$(CC) -o ./node4 obj/n4.o
n5:
	$(CC) $(CFLAGS) $(LIB) -c src/n5.c -o obj/n5.o
	$(CC) -o ./node5 obj/n5.o
n6:
	$(CC) $(CFLAGS) $(LIB) -c src/n6.c -o obj/n6.o
	$(CC) -o ./node6 obj/n6.o
n7:
	$(CC) $(CFLAGS) $(LIB) -c src/n7.c -o obj/n7.o
	$(CC) -o ./node7 obj/n7.o

run: 
	./node7 && fg & ./node6 && fg & ./node5 && fg & ./node3 && fg & ./node4 && fg & ./node2 && fg & ./node1

clean:
	rm obj/*.o
	rm ./node1 ./node2 ./node3 ./node4 ./node5 ./node6 ./node7 ./link1 ./link2 ./link3 ./link4 ./link5 ./link6
