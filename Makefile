# Option spécifique
# CC = gcc

CFLAGS = -Wall -g
.PHONY : all clean

all: main

clean:
	rm -f ./*.o main
	
# Construction des executables

o_main = main.o
l_main =-lGL -ldl -lGLEW -lglut

main: main.o
	$(CC) $(CFLAGS) -o $@ $(o_main) $(l_main)
	

# Dépendance des .o

#--------------------

vector.o : ./vector.h

#--------------------

mesh.o : ./mesh.h ./vector.h

#--------------------

scene.o : ./vector.h ./mesh.h ./scene.h

#--------------------
