# Public domain.

d2src = digest2.c d2cli.c d2math.c d2model.c d2modelio.c d2mpc.c d2ades.c common.c

digest2: Makefile $(d2src) digest2.h d2model.h
	gcc -ggdb -o digest2 -std=c99 -pthread $(d2src) -lm -lxml2

# indent options in .indent.pro
indent:
	indent *.c *.h
	rm *.c~ *.h~



