
playlife: lifefunc.o playlife.o
	gcc lifefunc.o gameoflife.o -o playlife

lifefunc.o: lifefunc.c playlife.h
	gcc -c lifefunc.c -o lifefunc.o

playlife.o: gameoflife.c playlife.h
	gcc -c gameoflife.c -o gameoflife.o

clean:
	rm *.o
	rm playlife

