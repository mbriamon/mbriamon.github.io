cmp = gcc
main = crossword
func = crosswordfunc
exec = runpath

runpath: crosswordfunc.o crossword.o 
	$(cmp) $(func).o $(main).o -lm -g -Wall -o $(exec)

crosswordfunc.o: crosswordfunc.c crosswordfunc.h 
	$(cmp) -c $(func).c -lm  -g -Wall -o $(func).o

crossword.o: crossword.c crosswordfunc.h
	$(cmp) -c $(main).c -lm -g -Wall -o $(main).o

clean:
	rm *.o
	rm $(exec)

