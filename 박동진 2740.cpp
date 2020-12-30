#include <stdio.h>
using namespace std;
FILE* in = stdin;
FILE* out = stdout;
int n, m, o;
int arr1[104][104], arr2[104][104], arr[104][104];

int main()
{
	fscanf(in, "%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			fscanf(in, "%d", &arr1[i][j]);
	fscanf(in, "%d%d", &m, &o);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < o; j++)
			fscanf(in, "%d", &arr2[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < o; j++)
			for (int k = 0; k < m; k++)
				arr[i][j] += arr1[i][k] * arr2[k][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < o; j++)
			fprintf(out, "%d ", arr[i][j]);
		fprintf(out, "\n");
	}


	return 0;
}