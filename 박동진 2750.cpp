#include <stdio.h>
#include <algorithm>
using namespace std;
FILE* in = stdin;
FILE* out = stdout;
int arr[1004];

int main()
{
	int n;
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; i++)
		fscanf(in, "%d", &arr[i]);
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
		fprintf(out, "%d\n", arr[i]);

	return 0;
}