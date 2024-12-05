cmp = gcc
main = usastates
func = statesfunc
exec = runpath

distancepath: statesfunc.o usastates.o 
	gcc statesfunc.o usastates.o -lm -o runpath

pathfunc.o: statesfunc.c statesfunc.h 
	gcc -c statesfunc.c -o statesfunc.o 

distancepath.o: usastates.c pathfunc.h
	gcc -c usastates.c -o usastates.o 

clean:
	rm *.o
	rm runpath
