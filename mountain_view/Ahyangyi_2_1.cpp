#include <stdio.h>
#include <vector>

using namespace std;

int n;
int data[2000];
vector<int> prev[2000];
int yy [2000];

bool ok;

bool judge (int l, int r)
{
    if (l >= r)
        return true;
    if (data[l] > r)
    {
//        printf ("judge failed in interval %d-%d\n", l, r);
        return false;
    }
    return judge (l + 1, data[l]) && judge(data[l], r);
}

void work (int x, int y, int slope, int dad)
{
    yy[x] = y;

    int ds = 0;
//    for (int i = prev[x].size() - 1; i >= 0; i --)
    for (int i = 0; i < prev[x].size(); i ++)
    {
        work (prev[x][i], y - (x - prev[x][i]) * slope, slope, x);
        slope ++;
    }
}

int main ()
{
    int t, ct = 0;

    for (scanf ("%d", &t); t > 0; t --)
    {
        scanf ("%d", &n);
        for (int i = 0; i < n - 1; i ++)
        {
            scanf ("%d", data + i);
            data[i] --;
        }

        for (int i = 0; i < n; i ++)
            prev[i].clear ();

        for (int i = 0; i < n - 1; i ++)
            prev[data[i]].push_back (i);

        bool ok = judge (0, n - 1);
//        ok = true;
        work (n - 1, 1000000000, 0, n - 1);
        
        printf ("Case #%d:", ++ ct);
        if (ok)
        {
            for (int i = 0; i < n; i ++)
                printf (" %d", yy[i]);
        }
        else
        {
            printf (" Impossible");
        }
        printf ("\n");
    }

    return 0;
}
