#include "ASCIIFun.h"

void ascii_plot_line
(int x0, int y0, int x1, int y1, int8_t *str, int col, char ch) {
	int del_x = abs(x1 - x0);
	int del_y = abs(y1 - y0);

	int error = 0;
	int del_err = (del_y + 1);

	int y = y0;
	int x = x0;

	int dir_y = y1 - y0;
	int dir_x = x1 - x0;

	if (dir_y > 0){
		dir_y = 1;
	}
	if (dir_y < 0){
		dir_y = -1;
	}

	if (dir_x > 0){
		dir_x = 1;
	}
	if (dir_x < 0){
		dir_x = -1;
	}

	if (del_y > del_x) {
		error = 0;
		del_err = (del_x + 1);
		x = x0;
		if (y0 < y1) {
			for (int y = y0; y < y1; y++) {
				error += del_err;
				str[y * col + x] = ch;
				if (error >= del_y + 1) {
					x += dir_x;
					error -= del_y  + 1;
				}
			} 
		} else {
			for (int y = y0; y > y1; y--) {
				error += del_err;
				str[y * col + x] = ch;
				if (error >= del_y + 1) {
					x += dir_x;
					error -= del_y  + 1;
				}
			} 
		}
	} else {
		error = 0;
		del_err = (del_y + 1);
		y = y0;
		if (x0 < x1) { 
			for (int x = x0; x < x1; x++) {
				error += del_err;
				str[y * col + x] = ch;
				if (error >= del_x + 1) {
					y += dir_y;
					error -= del_x + 1;
				}
			}
		} else {
			for (int x = x0; x > x1; x--) {
				error += del_err;
				str[y * col + x] = ch;
				if (error >= del_x + 1) {
					y += dir_y;
					error -= del_x + 1;
				}
			}
		}
	}

}
