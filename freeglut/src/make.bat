gcc -O2 -c -DFREEGLUT_STATIC *.c -I../include 
ar rcs libfreeglut32_static.a *.o