#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include "ASCIIFun.h"

#define BUFF_SIZE 	882
#define COL			42
#define ROW			21
#define RAD_X 		21
#define RAD_Y		10


int main()
{
	time_t result_time = time(NULL);
	struct tm *my_time = localtime(&result_time);
	int8_t str[BUFF_SIZE];
	int x0, y0,
		x1_sec, y1_sec,
		x1_min, y1_min,
		x1_h, y1_h;
	double  sec_ex = M_PI / 30.0;
	double 	min_ex = M_PI / 30.0;
	double 	h_ex = M_PI / 6.0;
	double angle_sec, angle_min,  angle_h;
	x0 = COL / 2;
	y0 = ROW / 2;
	int sec = my_time->tm_sec;
	int min = my_time->tm_min;
	int h = my_time->tm_hour;
	for (;;){
		if (sec == 60) {
			sec = 0;
			if (++min == 60) {
				min = 0;
				if (++h == 12) {
					h = 0;
				}
			}
		}
		memset (str, 32, BUFF_SIZE);

		angle_sec = M_PI_2 - sec++ * sec_ex;
		x1_sec = x0 + RAD_X * cos(angle_sec);
		y1_sec = y0 - RAD_Y * sin(angle_sec);

		angle_min = M_PI_2 - min * min_ex;
		x1_min = x0 + RAD_X * cos(angle_min);
		y1_min = y0 - RAD_Y * sin(angle_min);

		angle_h = M_PI_2 - h * h_ex;
		x1_h = x0 + RAD_X * cos(angle_h);
		y1_h = y0 - RAD_Y * sin(angle_h);

		ascii_plot_line (x0, y0, x1_h, y1_h, str, COL, '$');
		ascii_plot_line (x0, y0, x1_min, y1_min, str, COL, '@');
		ascii_plot_line (x0, y0, x1_sec, y1_sec, str, COL, '?');

		int temp = 0;
		for (int i = 0; i < BUFF_SIZE; i++) {
			putchar (str[i]);
			if (!(++temp % COL)){
				putchar(10);
				temp = 0;
			}
		}
		sleep(1);
		printf("\x1b[21A");
	}
	printf("\x1b[21B");
	return 0;
}
