#include <iostream>
#include <math.h>

using namespace std;

int Z(int n, int r, int c) 
{
	int cnt = 0, x, y, t;

	while (n != 0) {
		x = y = pow(2, n - 1);

		if (c < x && r < y) t = 0;
		else if (c >= x && r < y) t = 1;
		else if (c < x && r >= y) t = 2;
		else if (c >= x && r >= y) t = 3;

		cnt += pow(4, n - 1) * t;

		n--;
	}

	return cnt;
}

int main()
{
	int n, r, c;

	cin >> n >> r >> c;

	cout << Z(n, r, c);

	return 0;
}