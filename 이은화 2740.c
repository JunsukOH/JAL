#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	int matrixA[num1][num2] = { 0 };

	for (int i = 0; i < num1; i++) 
		for (int j = 0; j < num2; j++) 
			scanf("%d", &matrixA[i][j]);
			
	int test1, test2;
	scanf("%d %d", &test1, &test2);
	int matrixB[test1][test2];

	for (int i = 0; i < test1; i++)
		for (int j = 0; j < test2; j++)
			scanf("%d", &matrixB[i][j]);

	int matrixC[num1][test2];
	for (int i = 0; i < num1; i++)
		for (int j = 0; j < test2; j++)
			c[i][j] = 0;

	for (int i = 0; i < num1; i++)
		for (int j = 0; j < test2; j++)
			for (int k = 0; k < num2; k++)
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];

	for (int i = 0; i < num1; i++) {
		for (int j = 0; j < test2; j++)
			printf("%d ", matrixC[i][j]);
		printf("\n");
	}

	return 0;
}