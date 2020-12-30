#include <stdio.h>
#include <algorithm>
using namespace std;
FILE* in = stdin;
FILE* out = stdout;
int n, c, arr[200400];

int chk_val(int size)
{
	int st = 0;
	int val = 0;
	int f = 1;
	while (f)
	{
		for (int i = 1;; i++)
		{
			if (st + i == n)
			{
				f = 0;
				break;
			}
			if (arr[st + i] - arr[st] >= size)
			{
				val++;
				st = st + i;
				break;
			}
		}
	}
	return val;
}


int bin(int st, int ed, int key)
{
	int mid, val;
	while (ed > st)
	{
		mid = (st + ed) / 2;
		if (mid == 0)
		{
			st = 1;
			break;
		}
		val = chk_val(mid);
		if (val < key)
			ed = mid - 1;
		else
			st = mid + 1;
	}
	if (chk_val(st) >= key)
		return st;
	return st - 1;
}


int main()
{
	fscanf(in, "%d%d", &n, &c);
	for (int i = 0; i < n; i++)
		fscanf(in, "%d", &arr[i]);
	sort(arr, arr + n);
	fprintf(out, "%d", bin(1, (arr[n - 1] - arr[0]) / (c - 1), c - 1));

	return 0;
}