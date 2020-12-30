#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
FILE* in = stdin;
FILE* out = stdout;
int n, r, c, cnt = 0;

int main()
{
	fscanf(in, "%d%d%d", &n, &r, &c);
	int mid = pow(2, n - 1);
	while (mid != 0)
	{
		if (r >= mid)
		{
			cnt += mid * mid * 2;
			r -= mid;
		}
		if (c >= mid)
		{
			cnt += mid * mid;
			c -= mid;
		}
		mid /= 2;
	}
	fprintf(out, "%d", cnt);
	return 0;
}