#include <stdio.h>
FILE* in = stdin;
FILE* out = fopen("output.txt", "w");
int n;

int han(int a)
{
	int d = a % 10 - a / 10 % 10;
	while (a >= 10)
	{
		if (a % 10 - a / 10 % 10 != d)
			return 0;
		a /= 10;
	}
	return 1;
}


int main()
{
	int c = 0;

	fscanf(in, "%d", &n);

	for (int i = 1; i <= n; i++)
		if (han(i))
			c++;

	printf("%d", c);

	return 0;
}