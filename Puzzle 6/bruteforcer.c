#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char const alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const int len_alpha = 52;

const int half_len = 6;


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

char *int_to_str(char *buf, uint64_t num, int length) {
	for (int i = 0; i < length; i++) {
		buf[length-i-1] = alpha[(int)(num % len_alpha)];
		num /= len_alpha;
	}
	buf[length] = 0;
	return buf;
}

bool lookup(char *s, char **a, int max) {
	int min = 0;
	int mid;
	bool found = false;
	int i = 0;
	int len = strlen(s);
	while (min <= max && !found) {
		mid = (min + max) / 2;
		int res = strcmp(s, a[mid]);
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
	return false;
}

char *get_even(char *s, char *buf) {
	for (int i = 0; i < half_len; i++) {
		buf[i] = s[2 * i];
	}
	buf[half_len] = 0;
	return buf;
}

int main(int argc, char* argv[])
{

	char **left = (char**)malloc(sizeof(char*) * 1048576);
	char **right = (char**)malloc(sizeof(char*) * 1048576);
	char **even = (char**)malloc(sizeof(char*) * 1048576);
	int num_left = 0;
	int num_right = 0;
	int num_even = 0;

	uint64_t max = expo(len_alpha, half_len);
	uint64_t prog = max / 10000;
	printf("%llu total permutations\n", max);
	char *str = (char*)malloc(sizeof(char) * half_len + 1);
	for (uint64_t i = 0; i < max; i++) {
		int_to_str(str, i, half_len);
		int chksum = check(str);
		switch (chksum) {
		case 0x0000:
			even[num_even++] = str;
			str = (char*)malloc(sizeof(char) * half_len + 1);
			break;
		case 0xd06e:
			left[num_left++] = str;
			str = (char*)malloc(sizeof(char) * half_len + 1);
			break;
		case 0xf00d:
			right[num_right++] = str;
			str = (char*)malloc(sizeof(char) * half_len + 1);
			break;
		}
		if (i % prog == 0) {
			printf("%llu/%llu completed (%i left, %i right, %i even)\n", i, max, num_left, num_right, num_even);
		}
	}
	printf("%i left, %i right, %i even\n", num_left, num_right, num_even);
	FILE *lf, *rf, *ef;
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
	fclose(lf);
	fclose(rf);
	fclose(ef);
	printf("Starting part 2 bruteforce (possibly bugged)\n");
	char *s_buf = (char*)malloc(sizeof(char) * half_len * 2 + 1);
	char *e_buf = (char*)malloc(sizeof(char) * half_len + 1);
	for (int i = 0; i < num_left; i++) {
		for (int j = 0; j < num_right; j++) {
			strcpy(s_buf, left[i]);
			strcat(s_buf, right[i]);
			get_even(s_buf, e_buf);
			if (lookup(e_buf, even, num_even)) {
				printf("FOUND: %s (%s)\n", s_buf, e_buf);
				return 0;
			}
		}
	}
	return 0;
}
