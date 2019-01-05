#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ulong_t;

typedef struct {
	ulong_t data[2][2];
} fb_matrix_t;

ulong_t fb_normal(int n);
ulong_t fb_divide_conquer(int n);
fb_matrix_t fb_multiply_matrix(fb_matrix_t m1, fb_matrix_t m2);

#endif
