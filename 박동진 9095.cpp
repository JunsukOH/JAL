#include <stdio.h>
FILE* in = stdin;
FILE* out = stdout;

int main()
{
    int n, i, j, a = 0;
    int board[14];
    int arr[14][3];
    fscanf(in, "%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(in, "%d", &board[i]);
        if (board[i] > a)
            a = board[i];
    }
    arr[1][0] = 1;
    arr[1][1] = 0;
    arr[1][2] = 0;
    arr[2][0] = 1;
    arr[2][1] = 1;
    arr[2][2] = 0;
    arr[3][0] = 2;
    arr[3][1] = 1;
    arr[3][2] = 1;

    for (j = 4; j <= a; j++)
    {
        arr[j][0] = arr[j - 1][0] + arr[j - 1][1] + arr[j - 1][2];
        arr[j][1] = arr[j - 2][0] + arr[j - 2][1] + arr[j - 2][2];
        arr[j][2] = arr[j - 3][0] + arr[j - 3][1] + arr[j - 3][2];
    }

    for (i = 0; i < n; i++)
        fprintf(out, "%d ", arr[board[i]][0] + arr[board[i]][1] + arr[board[i]][2]);

    return 0;
}
