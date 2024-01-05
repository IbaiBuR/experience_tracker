cd ../src
gcc -c main.c experience.c util.c
gcc -o experience_tracker main.o experience.o util.o
del *.o