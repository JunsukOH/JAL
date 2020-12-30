#include <stdio.h>
#include <vector>
using namespace std;
FILE* in = stdin;
FILE* out = stdout;
vector<int> heap;
int n;

void heap_sort(int pos)
{
	while (pos != 1)
	{
		if (heap[pos / 2] < heap[pos])
		{
			int tmp = heap[pos / 2];
			heap[pos / 2] = heap[pos];
			heap[pos] = tmp;
		}
		pos /= 2;
	}
}


void find(int a)
{
	if (a == n + 1)
	{
		for (int i = 1; i < heap.size(); i++)
			fprintf(out, "%d ", heap[i]);
		return;
	}
	if (a != 1)
	{
		heap[a - 1] = a;
		heap_sort(a - 1);
	}
	heap.push_back(1);

	find(a + 1);
}


int main()
{
	fscanf(in, "%d", &n);
	heap.push_back(-1);
	find(1);

	return 0;
}