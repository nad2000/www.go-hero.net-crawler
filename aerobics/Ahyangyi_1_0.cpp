#include <stdio.h>
#include <tr1/random>

using namespace std;
using namespace std::tr1;

int t;
int n, w, l;
int r[1000];
long long x[1000], y[1000];

int main ()
{
    int ct = 0;
    mt19937 rand;

    for (scanf ("%d", &t); t > 0; t --)
    {
        scanf ("%d%d%d", &n, &w, &l);
        for (int i = 0; i < n; i ++)
            scanf ("%d", r + i);

        std::tr1::uniform_int<long long> uniw(0, w * 100LL);
        std::tr1::uniform_int<long long> unil(0, l * 100LL);

        for (int i = 0; i < n; i ++)
        {
            bool ok;

            do {
                x[i] = uniw(rand);
                y[i] = unil(rand);

                ok = true;

                for (int j = 0; j < i; j ++)
                    if ((x[j] - x[i]) * (double)(x[j] - x[i]) + (y[j] - y[i]) * (double)(y[j] - y[i]) <= (r[i] + r[j]) * (double)(r[i] + r[j]) * 10000.001)
                        ok = false;
                }
            while (!ok);
        }

        printf ("Case #%d:", ++ct);
        for (int i = 0; i < n; i ++)
            printf (" %lld.%d%d %lld.%d%d", x[i] / 100, (int)(x[i] / 10 % 10), (int)(x[i] % 10)
                        , y[i] / 100, (int)(y[i] / 10 % 10), (int)(y[i] % 10));
        printf ("\n");
    }

    return 0;
}
