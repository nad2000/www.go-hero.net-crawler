#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void redirect(int argc, const char **argv)
{
    if (argc > 1)
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) { perror(argv[1]); exit(1); }
        if (-1 == dup2(fd, 0)) { perror(argv[1]); exit(1); }
        if (-1 == close(fd)) { perror(argv[1]); exit(1); }
    }

    if (argc > 2)
    {
        int fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
        if (fd == -1) { perror(argv[2]); exit(1); }
        if (-1 == dup2(fd, 1)) { perror(argv[2]); exit(1); }
        if (-1 == close(fd)) { perror(argv[2]); exit(1); }
    }
}

static const int dr[3] = {0, 0, 1};
static const int dc[3] = {-1, 1, 0};

struct span
{
    int r;
    int c0, c1;
    bool live;
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int R, C;
        cin >> R >> C;
        vs grid(R);
        vector<pii> caves;
        for (int i = 0; i < R; i++)
            cin >> grid[i];
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
            {
                if (grid[i][j] >= '0' && grid[i][j] <= '9')
                {
                    int id = grid[i][j] - '0';
                    if (SZ(caves) <= id)
                        caves.resize(id + 1);
                    caves[id] = pii(i, j);
                }
            }

        printf("Case #%d:\n", cas + 1);
        for (int cave = 0; cave < SZ(caves); cave++)
        {
            int r0 = caves[cave].first;
            int c0 = caves[cave].second;
            vector<vector<bool> > reach(R, vector<bool>(C, false));
            queue<pii> q;
            q.push(pii(r0, c0));
            reach[r0][c0] = true;
            int sc = 0;
            while (!q.empty())
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                sc++;
                for (int d = 0; d < 3; d++)
                {
                    int r2 = r - dr[d];
                    int c2 = c - dc[d];
                    if (grid[r2][c2] != '#' && !reach[r2][c2])
                    {
                        reach[r2][c2] = true;
                        q.push(pii(r2, c2));
                    }
                }
            }

            vector<vi> spanid(R, vi(C, -1));
            vector<span> spans;
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    if (reach[i][j] && spanid[i][j] == -1)
                    {
                        int x = j;
                        while (reach[i][x])
                            x++;
                        for (int k = j; k < x; k++)
                            spanid[i][k] = spans.size();
                        span s;
                        s.r = i;
                        s.c0 = j;
                        s.c1 = x;
                        s.live = true;
                        spans.push_back(s);
                    }

            bool more = true;
            while (more)
            {
                more = false;
                for (int pos = 0; pos < C; pos++)
                    for (int gap = 0; gap < C; gap++)
                    {
                        vector<int> elim;
                        bool safe = true;
                        for (int i = 0; i < SZ(spans); i++)
                        {
                            const span &s = spans[i];
                            if (s.live)
                            {
                                int p = min(s.c0 + pos, max(s.c0, s.c1 - 1 - gap));
                                if (grid[s.r + 1][p] != '#')
                                {
                                    if (!reach[s.r + 1][p])
                                    {
                                        safe = false;
                                        break;
                                    }
                                    else
                                        elim.push_back(i);
                                }
                            }
                        }
                        if (safe && !elim.empty())
                        {
                            more = true;
                            for (int i = 0; i < SZ(elim); i++)
                                spans[elim[i]].live = false;
                        }
                    }
            }

            bool lucky = true;
            for (int i = 0; i < SZ(spans); i++)
                if (spans[i].live)
                {
                    const span &s = spans[i];
                    if (!(s.r == r0 && s.c0 <= c0 && c0 < s.c1))
                    {
                        lucky = false;
                        break;
                    }
                }
            cout << cave << ": " << sc << ' ';
            if (lucky)
                cout << "Lucky\n";
            else
                cout << "Unlucky\n";
        }
    }
    return 0;
}
