TARGETS = pig

all: $(TARGETS)

pig: pig.o
	gccx -o pig pig.o

pig.o: pig.c
	gccx -c pig.c
