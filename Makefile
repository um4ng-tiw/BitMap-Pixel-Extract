image:
	gcc -c main.c -o main.o
	gcc -c bitmap_control.c -o bitmap_control.o
	gcc main.o bitmap_control.o -o result
	./result.exe