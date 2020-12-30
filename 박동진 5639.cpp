#include <stdio.h>
#include <vector>
using namespace std;
FILE* in = stdin;
FILE* out = stdout;
struct _mu { int v; int m; };	//max, value
vector<_mu> sta;

void pop()
{
	fprintf(out, "%d\n", sta[sta.size() - 1].v);
	sta.pop_back();
}

int main()
{
	int f = 1;
	while (1)
	{
		_mu a;
		if (fscanf(in, "%d", &a.v) == EOF)
			break;
		if (sta.empty())
		{
			a.m = 1004004;
			sta.push_back(a);
		}
		else
		{
			if (a.v < sta[sta.size() - 1].v)
			{
				a.m = sta[sta.size() - 1].v;
				sta.push_back(a);
			}
			else
			{
				while (a.v > sta[sta.size() - 1].m)
					pop();
				a.m = sta[sta.size() - 1].m;
				sta.push_back(a);
			}
		}

	}
	while (sta.size() != 0)
		pop();

	return 0;
}