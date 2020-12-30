#include <stdio.h>
#include <algorithm>
using namespace std;
FILE* in = stdin;
int arr[5004];

int main()
{
	int n;
	fscanf(in, "%d", &n);
	arr[3] = 1;
	arr[5] = 1;
	for (int i = 1; i <= 5000; i++)
	{
		if (arr[i] == 0)
			continue;
		if (arr[i + 3])
			arr[i + 3] = min(arr[i + 3], arr[i] + 1);
		else
			arr[i + 3] = arr[i] + 1;
		if (arr[i + 5])
			arr[i + 5] = min(arr[i + 5], arr[i] + 1);
		arr[i + 5] = arr[i] + 1;
	}
	if (arr[n] == 0)
		printf("-1");
	else
		printf("%d", arr[n]);


	return 0;
}
