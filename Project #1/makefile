all: mcquad burger burger2

runall: runmcquad runburger runburger2

runmcquad: mcquad
	mcquad mcquad.in

runburger: burger
	burger burger.in

runburger2: burger2
	burger2 burger2.in

mcquad: mcquad.o
	gcc -o mcquad mcquad.o -lm

mcquad.o: mcquad.c
	gcc -c mcquad.c

burger: burger.o
	gcc -o burger burger.o -lm

burger.o: burger.c
	gcc -c burger.c

burger2: burger2.o
	gcc -o burger2 burger2.o -lm

burger2.o: burger2.c
	gcc -c burger2.c

clean:
	rm *.o mcquad burger burger2

