#include <stdio.h>
FILE* in = stdin;
FILE* out = stdout;
struct _xyv { int x; int y; int v; };
int n, m, t = 0, h = 0;
char arr[104][104];
int dir[4][2] = { {0,1} ,{0,-1},{1,0},{-1,0} };
_xyv que[10004];

void push(int y, int x, int v)
{
	que[h].v = v;
	que[h].x = x;
	que[h++].y = y;
	h %= 10000;
}

void pop()
{
	t++;
	t %= 10000;
}

int bfs(int y, int x, int val)
{
	for (int i = 0; i < 4; i++)
	{
		int Y = y + dir[i][0];
		int X = x + dir[i][1];
		if (X < 0 || Y < 0 || X >= m || Y >= n)
			continue;
		if (Y == n - 1 && X == m - 1)
			return val + 1;
		if (arr[Y][X] == 1)
		{
			arr[Y][X]--;
			push(Y, X, val + 1);
		}
	}
	return 0;
}

int main()
{
	fscanf(in, "%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		fscanf(in, "%s", arr[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] -= '0';
	arr[0][0]--;
	push(0, 0, 1);
	while (1)
	{
		if (t == h)
			break;
		int ans = bfs(que[t].y, que[t].x, que[t].v);
		if (ans)
		{
			fprintf(out, "%d", ans);
			return 0;
		}
		pop();
	}

	return 0;
}