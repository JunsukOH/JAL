#include <stdio.h>
#include <vector>
using namespace std;
FILE* in = stdin;
FILE* out = stdout;
struct _se { int st, ed; };
vector <_se> arr;

void mov(int a, int pos, int fin)
{
	if (a > 1)
		mov(a - 1, pos, 6 - pos - fin);
	_se i;
	i.st = pos;
	i.ed = fin;
	arr.push_back(i);
	if (a > 1)
		mov(a - 1, 6 - pos - fin, fin);

	return;
}

int main()
{
	int n;
	fscanf(in, "%d", &n);
	mov(n, 1, 3);
	fprintf(out, "%d\n", arr.size());
	for (int i = 0; i < arr.size(); i++)
		fprintf(out, "%d %d\n", arr[i].st, arr[i].ed);
	return 0;
}
