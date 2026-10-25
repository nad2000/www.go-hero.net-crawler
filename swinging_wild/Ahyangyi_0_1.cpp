#include <stdio.h>
#include <string.h>

int t;
int n;
int x[10000], y[10000], X;
int hold[10000];

int main ()
{
    int ct = 0;
    bool ans;

    for (scanf ("%d", &t); t > 0; t --)
    {
        scanf ("%d", &n);
        for (int i = 0; i < n; i ++)
            scanf ("%d%d", x + i, y + i);
        scanf ("%d", &X);

        memset(hold, 0, sizeof(hold));
        hold[0] = x[0];

        ans = false;

        int ii = 1;

        for (int i = 0; i < n; i ++)
        {
            if (y[i] < hold[i])
                hold[i] = y[i];
            if (hold[i] + x[i] >= X)
                ans = true;

            for (; ii < n && hold[i] + x[i] >= x[ii]; ii ++)
            {
                hold[ii] = x[ii] - x[i];
            }
        }


        printf ("Case #%d: %s\n", ++ ct, ans? "YES" : "NO");
    }

    return 0;
}
