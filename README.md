# BitMap-Pixel-Extract
A simple C library to extract pixel data from 8-bit Bitmap images with example usage. The example describes adding a value of 50 to all the pixels

### Running the project
If make is present in your system you can use the makefile to compile and execute the code

```
make
```

If make is not present
```
gcc -c main.c -o main.o
gcc -c bitmap_control.c -o bitmap_control.o
gcc main.o bitmap_control.o -o result
./result.exe
```
