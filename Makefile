mains: main.o libmyBank.a
	gcc -Wall -o mains main.o -L. libmyBank.a
	
maind: main.o libmyBank.so
	gcc -Wall -o maind main.o -L. ./libmyBank.so
	
mybanks: libmyBank.a
	
libmyBank.a: myBank.h myBank.o 
	ar -rcs libmyBank.a myBank.h myBank.o
	
mybankd: libmyBank.so

libmyBank.so: myBank.o 
	gcc -o libmyBank.so myBank.o -shared
	
myBank.o: myBank.c myBank.h
	gcc -Wall -c myBank.c
	


main.o: main.c myBank.h
	gcc -Wall -c main.c
	
all: mains maind

clean:
	rm -f *.o *.a *.so mains maind