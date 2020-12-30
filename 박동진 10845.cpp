#include <stdio.h>
#include <string.h>
FILE* in = stdin;
FILE* out = stdout;
main()
{
    int n, c, y, tail = 0, head = 0;
    int que[10000] = { 0, };
    char x[10];
    fscanf(in, "%d", &n);
    for (c = 0; c < n; c++)
    {
        fscanf(in, "%s", x);
        if (strcmp("push", x) == 0)
        {
            fscanf(in, "%d", &y);
            que[tail++] = y;
        }
        if (strcmp("pop", x) == 0)
        {
            if (tail == head)
                fprintf(out, "-1\n");
            else
                fprintf(out, "%d\n", que[head++]);
        }
        if (strcmp("size", x) == 0)
        {
            fprintf(out, "%d\n", tail - head);
        }
        if (strcmp("empty", x) == 0)
        {
            if (tail == head)
                fprintf(out, "1\n");
            else
                fprintf(out, "0\n");
        }
        if (strcmp("front", x) == 0)
        {
            if (tail == head)
                fprintf(out, "-1\n");
            else
                fprintf(out, "%d\n", que[head]);
        }
        if (strcmp("back", x) == 0)
        {
            if (tail == head)
                fprintf(out, "-1\n");
            else
                fprintf(out, "%d\n", que[tail - 1]);
        }
    }
}