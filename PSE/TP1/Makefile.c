# Compilation p1.c (contient say_hello)
p1.h : p1.c
		gcc p1.c -o

# Compilation p2.c
p2.x : p2.o
		gcc p2.c -o

# Creation p2.o
p2.o : p2.c
		gcc p2.c -c
