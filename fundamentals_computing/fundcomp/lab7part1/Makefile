cmp = gcc
main = path
func = pathfunc
exec = runpath

distancepath: pathfunc.o path.o 
	gcc pathfunc.o path.o -lm -o runpath

pathfunc.o: pathfunc.c pathfunc.h 
	gcc -c pathfunc.c -o pathfunc.o 

distancepath.o: path.c pathfunc.h
	gcc -c path.c -o path.o 

clean:
	rm *.o
	rm runpath

