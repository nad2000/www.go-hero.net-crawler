#include <stdio.h>

int n, s, p;

int main ()
{
    int t, ct = 0;

    for (scanf ("%d", &t); t > 0; t --)
    {
        int a1 = 0, a2 = 0;

        scanf ("%d%d%d", &n, &s, &p);

        int p1, p2;

        if (p == 0)
            p1 = 0;
        else
            p1 = (p - 1) + (p - 1) + p;
        if (p == 0)
            p2 = 0;
        else if (p == 1)
            p2 = 1;
        else
            p2 = (p - 2) + (p - 2) + p;

        for (int i = 0; i < n; i ++)
        {
            int x;

            scanf ("%d", &x);

            if (x >= p1)
                a1 ++;
            else
                if (x >= p2)
                    a2 ++;
        }

        int ans = a1;
        if (a2 < s)
            ans += a2;
        else
            ans += s;

        printf ("Case #%d: %d\n", ++ct, ans);
    }

    return 0;
}
