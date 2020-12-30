#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int input[1000];
int main() {
	int min, temp, index, num;

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &input[i]);
	}

	for (int i = 0; i < num; i++) {
		min = 1001;

		for (int j = i; j < num; j++) {

			if (min > input[j]) {
				min = input[j];
				index = j;
			}
		}

		temp = input[i];
		input[i] = input[index];
		input[index] = temp;
	}

	for (int i = 0; i < num; i++) {
		printf("%d\n", input[i]);
	}
	return 0;
}