TARGETS = pig unpig elmer izzle

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

izzle: izzle.o
	gccx -o izzle izzle.o

izzle.o: izzle.c
	gccx -c izzle.c

clean: pig pig.o unpig unpig.o elmer elmer.o izzle izzle.o
	rm pig
	rm pig.o
	rm unpig
	rm unpig.o
	rm elmer
	rm elmer.o
	rm izzle
	rm izzle.o
