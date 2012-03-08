#include <stdio.h>

typedef unsigned long ulong;

void convert_num(ulong val, int len, int right, char *buf)
{
	ulong j, k;
	int i, flag=0;

	if (val > 999999999 || len > 9) {
		return;
	}
	for(i=0, j=1; i<len-1; i++) {
		j *= 10;
	}
	if (!right) {
		for (i=0; j>0; j/=10) {
			k = val/j;
			if (k > 9) {
				j *= 100;
				continue;
			}
			if (flag || k || j == 1) {
				buf[i++] = k + '0';
				flag++;
			} else {
				buf[i++] = ' ';
			}
			val -= k * j;
		}
	} else {
		for(i=0; i<len; j/=10) {
			if (j) {
				k = val/j;
					if (k > 9) {
					j *= 100;
					len++;
					continue;
				}
				if (k == 0 && flag == 0) {
					continue;
				}
				buf[i++] = k + '0';
				val -= k * j;
			} else {
				if (flag == 0 &&  i < len-1) {
					buf[i++] = '0';
				} else {
					buf[i++] = ' ';
				}
			}
			flag++;
		}
	}

	buf[i] = 0;
}

int main(int argc, char **argv)
{
	char buf[10] = {0};
	convert_num(12345, 6, 0, buf);
	printf("[%11s]\n", buf);
	convert_num(12345, 6, 1, buf);
	printf("[%11s]\n", buf);
	convert_num(12345789, 6, 0, buf);
	printf("[%11s]\n", buf);
	convert_num(1 << 21, 6, 0, buf);
	printf("[%11s]\n", buf);
	return 0;
}
