all:	main.o 
		gcc main.o -o main
main.o:	main.cpp 
		gcc -c main.cpp -o main.o
clean:
		rm -f *.o main
		