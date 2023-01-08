#ifndef GETWORD_H_
#define GETWORD_H_

#include <stdio.h>

extern int getword(FILE *fp, char *buf, int size, int first(int c), int rest(int c));

#endif  // GETWORD_H_