#include <stdio.h>
#include <string.h>

#include <set>
#include <queue>

using namespace std;

int t;
char map[60][60];
int x[10], y[10], k;
int vst[60][60];
int p[10], q[10];
int n, m;

struct state
{
    bool ok[60][60];
} cur, next;

set<state> S;
queue<state> Q;

void getNext (int dx, int dy)
{
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            next.ok[i][j] = false;    
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            if (cur.ok[i][j])
            {
                if (map[i + dx][j + dy] == '.')
                    next.ok[i + dx][j + dy] = true;
                else
                    next.ok[i][j] = true;
            }
}

bool operator < (const state& a, const state& b)
{
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            if (vst[i][j] && a.ok[i][j] != b.ok[i][j])
                return a.ok[i][j] < b.ok[i][j];
    return false;
}

void add (const state& x)
{
    for (int i = 0; i <n; i ++)
        for (int j = 0; j <m; j ++)
            if (!vst[i][j] && x.ok[i][j])
                return;
    if (S.find(x) == S.end())
    {
        S.insert (x);
        Q.push(x);
    }
}

int fill (int x, int y)
{
    if (vst[x][y]) return 0;
    int ans = 1;

    vst[x][y] = 1;
    if (x - 1 >= 0 && map[x - 1][y] == '.')
        ans += fill(x - 1, y);
    if (y - 1 >= 0 && map[x][y - 1] == '.')
        ans += fill(x, y - 1);
    if (y + 1 < m && map[x][y + 1] == '.')
        ans += fill(x, y + 1);

    return ans;
}

int main ()
{
    int ct = 0;

    for (scanf ("%d", &t); t > 0; t --)
    {
        scanf ("%d%d", &n, &m);

        k = 0;

        for (int i = 0 ;i < n; i ++)
            for (int j = 0; j < m; j ++)
            {
                do scanf ("%c", map[i] + j);
                    while (map[i][j] <= ' ');

                if (map[i][j] >= '0' && map[i][j] <= '9')
                {
                    x[map[i][j] - '0'] = i;
                    y[map[i][j] - '0'] = j;
                    if (map[i][j] - '0' + 1 > k)
                        k = map[i][j] - '0' + 1;

                    map[i][j] = '.';
                }
            }

        for (int i = 0; i < k; i ++)
        {
            memset (vst, 0, sizeof(vst));
            p[i] = fill (x[i], y[i]);

            for (int j = 0; j < n; j ++)
                for (int k = 0; k < m; k ++)
                    cur.ok[j][k] = vst[j][k];

            S.clear ();
            add (cur);

            while (!Q.empty ())
            {
                cur = Q.front ();
                Q.pop ();

                getNext (1, 0);
                add (next);
                getNext (0, -1);
                add (next);
                getNext (0, 1);
                add (next);
            }

            for (int j = 0; j < n; j ++)
                for (int k = 0; k < m; k ++)
                    cur.ok[j][k] = (j == x[i] && k == y[i]);
            if (S.find(cur) != S.end())
                q[i] = 1;
            else
                q[i] = 0;
        }

        printf ("Case #%d:\n", ++ct);
        for (int i = 0; i < k; i ++)
            printf ("%d: %d %s\n", i, p[i], q[i]? "Lucky" : "Unlucky");
    }

    return 0;

}
