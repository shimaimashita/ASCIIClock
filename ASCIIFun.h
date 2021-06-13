#ifndef ASCIIFUN_H
#define ASCIIFUN_H

#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

void ascii_plot_line
(int x0, int y0, int x1, int y1, int8_t *str, int col, char ch);

#endif
