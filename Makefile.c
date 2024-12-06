CC = gcc
all : main

main : main.o cmdcalc.o print.o cmdcalc.h
		$(CC) main.o cmdcalc.o print.o - o main

main.o : main.c cmdcalc.h
		$(CC) - c main.c

cmdcalc.o : cmdcalc.c cmdcalc.h
		$(CC) - c cmdcalc.c

print.o : print.c cmdcalc.h
		$(CC) - c print.c


clean :
		rm - rf * .o main
