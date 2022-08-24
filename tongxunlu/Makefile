main: main.o func.o
	gcc main.o func.o -o main
main.o: main.c func.h
	gcc -c main.c
func.o: func.c func.h
	gcc -c func.c
clean: 
	rm -f *.o main
cleanmessage:
	rm -f message.txt
