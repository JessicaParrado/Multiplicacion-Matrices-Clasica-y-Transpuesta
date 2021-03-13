
GCC = gcc
FLAGS = -std=c99 -pedantic -Wall
CFLAGS = -lm
PROGS = principalClasica
PROGS2 = principalTranspuesta
all: principalClasica

principalClasica:
	$(GCC) $(FLAGS) -c modulo.c -fopenmp
	$(GCC) $(FLAGS) -c $@.c -fopenmp
	$(GCC) $(FLAGS) -c principalTranspuesta.c -fopenmp
	$(GCC) $(FLAGS) -o $@ $@.o modulo.o -fopenmp
	$(GCC) $(FLAGS) -o principalTranspuesta principalTranspuesta.o modulo.o -fopenmp

clean:
	$(RM) $(PROGS) *.o
	$(RM) $(PROGS2) *.o

