#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;
FILE* in = stdin;
FILE* out = stdout;
int n, m;
stack <int> sta;

int main()
{
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		int c;
		char order[14];
		fscanf(in, "%s", order);
		if (order[0] == 'p' && order[1] == 'u')
		{
			fscanf(in, "%d", &c);
			sta.push(c);
		}
		else if (order[0] == 's')
			fprintf(out, "%d\n", sta.size());
		else if (order[0] == 'e')
			fprintf(out, "%d\n", sta.empty());
		else
		{
			if (sta.size() == 0)
			{
				fprintf(out, "-1\n");
				continue;
			}
			fprintf(out, "%d\n", sta.top());
			if (order[0] == 'p')
				sta.pop();
		}
	}
	return 0;
}