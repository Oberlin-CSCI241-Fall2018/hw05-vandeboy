TARGETS = pig unpig elmer

all: $(TARGETS)

pig: pig.o
	gccx -o pig pig.o

pig.o: pig.c
	gccx -c pig.c

unpig: unpig.o
	gccx -o unpig unpig.o

unpig.o: unpig.c
	gccx -c unpig.c

elmer: elmer.o
	gccx -o elmer elmer.o

elmer.o: elmer.c
	gccx -c elmer.c
