// CHash.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdint>
#include <cstring>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 1

char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int len_alpha = strlen(alpha);

int half_len = 6;

char **left = (char**)malloc(sizeof(char*) * 1048576);
char **right = (char**)malloc(sizeof(char*) * 1048576);
char **even = (char**)malloc(sizeof(char*) * 1048576);
int num_left = 0;
int num_right = 0;
int num_even = 0;

uint64_t expo(uint64_t a, int b){
	uint64_t result = 1;

	while (b){
		if (b & 1){
			result *= a;
		}
		b >>= 1;
		a *= a;
	}

	return result;
}

int check(char *str) {
	int a = 0;
	int b = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		a = (a + str[i]) % 0xff;
		b = (b + a) % 0xff;
	}
	return ((b & 0xff) << 8) | (a & 0xff);
}

char *int_to_str(uint64_t num, int length) {
	char *ret = (char*)malloc(sizeof(char) * length + 1);
	for (int i = 0; i < length; i++) {
		ret[length-i-1] = alpha[(int)(num % len_alpha)];
		num /= len_alpha;
	}
	ret[length] = 0;
	return ret;
}

bool lookup(char *s) {
	int min = 0;
	int max = num_even;
	int mid;
	bool found = false;
	int i = 0;
	int len = strlen(s);
	while (min <= max && !found) {
		mid = (min + max) / 2;
		int res = strcmp(s, even[mid]);
		if (!res) {
			return true;
		}
		else if (res < 0) {
			max = mid - 1;
		}
		else {
			min = mid + 1;
		}
	}
}

char *get_even(char *s, char *buf) {
	for (int i = 0; i < half_len; i++) {
		buf[i] = s[2 * i];
	}
	buf[half_len] = 0;
	return buf;
}

int _tmain(int argc, _TCHAR* argv[])
{
	uint64_t max = expo(len_alpha, half_len);
	uint64_t prog = max / 10000;
	printf("%I64d total permutations\n", max);
	for (uint64_t i = 0; i < max; i++) {
		char *str = int_to_str(i, half_len);
		int chksum = check(str);
		switch (chksum) {
		case 0x0000:
			even[num_even++] = str;
			//printf("String %s (checksum %i) added to even (%i total)\n", str, chksum, num_even);
			break;
		case 0xd06e:
			left[num_left++] = str;
			//printf("String %s (checksum %i) added to left (%i total)\n", str, chksum, num_left);
			break;
		case 0xf00d:
			right[num_right++] = str;
			//printf("String %s (checksum %i) added to right (%i total)\n", str, chksum, num_right);
			break;
		default:
			free(str);
		}
		if (i % prog == 0) {
			printf("%I64d/%I64d completed (%i left, %i right, %i even)\n", i, max, num_left, num_right, num_even);
		}
	}
	printf("%i left, %i right, %i even\n", num_left, num_right, num_even);
	FILE *lf, *rf, *ef;
	/*
	char *mode = "w";
	lf = fopen("left.txt", mode);
	rf = fopen("right.txt", mode);
	ef = fopen("even.txt", mode);
	for (int i = 0; i < num_left; i++) {
		fprintf(lf, "%s\n", left[i]);
	}
	for (int i = 0; i < num_right; i++) {
		fprintf(rf, "%s\n", right[i]);
	}
	for (int i = 0; i < num_even; i++) {
		fprintf(ef, "%s\n", even[i]);
	}
	*/
	char *mode = "r";
	lf = fopen("left.txt", mode);
	rf = fopen("right.txt", mode);
	ef = fopen("even.txt", mode);
	fclose(lf);
	fclose(rf);
	fclose(ef);
	printf("Starting part 2 bruteforce\n");
	char *s_buf = (char*)malloc(sizeof(char) * half_len * 2 + 1);
	char *e_buf = (char*)malloc(sizeof(char) * half_len + 1);
	for (int i = 0; i < num_left; i++) {
		for (int j = 0; j < num_right; j++) {
			strcpy(s_buf, left[i]);
			strcat(s_buf, right[i]);
			get_even(s_buf, e_buf);
			if (lookup(e_buf)) {
				printf("FOUND: %s (%s)\n", s_buf, e_buf);
				return 0;
			}
		}
	}
	return 0;
}
