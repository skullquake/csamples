#ifndef GETCH_H
#define GETCH_H
/*
 * getch()
 *  a nonstandard function and is present in conio.h header file
 *  which is mostly used by MS-DOS compilers like Turbo C. It is not part
 *  of the C standard library or ISO C, nor is it defined by POSIX
 *  (Source: http://en.wikipedia.org/wiki/Conio.h)
 */
#include<stdio.h>
#include<termios.h>
static struct termios old, new;
/* Initialize new terminal i/o settings */
void initTermios(int echo);
/* Restore old terminal i/o settings */
void resetTermios(void);
char getch_(int echo);
/* Read 1 character without echo */
char getch(void);
/* Read 1 character with echo */
char getche(void);
#endif
