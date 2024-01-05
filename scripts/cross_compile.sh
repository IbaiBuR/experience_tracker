cd src
x86_64-w64-mingw32-gcc -I/usr/x86_64-w64-mingw32/sys-root/mingw/include/ -o experience_tracker main.c experience.c util.c -static -lncursesw -L/usr/x86_64-w64-mingw32/sys-root/mingw/bin/ -DNCURSES_STATIC
make clean