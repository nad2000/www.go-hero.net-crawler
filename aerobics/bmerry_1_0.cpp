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

struct student
{
    int r;
    int id;
    int x;
    int y;

    bool operator<(const student &s) const { return r > s.r; }
};

static void fit(vector<student> &S, int &cur, int x0, int y0, int x1, int y1, bool o0, bool o1)
{
    if (cur == SZ(S))
        return;
    student &s = S[cur];
    if (2 * s.r > x1 - x0)
        return;
    s.x = x0 + s.r;
    s.y = y0 + s.r;
    if (o0)
        s.y -= s.r;
    int top = y1;
    if (o1)
        top += s.r;
    if (s.y + s.r > top)
        return;
    cur++;
    if (s.r * 4 > y1 - y0)
    {
        fit(S, cur, x0 + 2 * s.r, y0, x1, y1, o0, o1);
        fit(S, cur, x0, s.y + s.r, x0 + 2 * s.r, y1, false, o1);
    }
    else
    {
        fit(S, cur, x0 + 2 * s.r, y0, x1, s.y + s.r, o0, false);
        fit(S, cur, x0, s.y + s.r, x1, y1, false, o1);
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int N, W, L;
        cin >> N >> W >> L;
        bool swapped = W < L;
        if (swapped)
        {
            swap(W, L);
        }
        vector<student> S(N);
        for (int i = 0; i < N; i++)
        {
            cin >> S[i].r;
            S[i].id = i;
        }
        sort(RA(S));
        int cur = 0;
        fit(S, cur, 0, 0, W, L, true, true);
        assert(cur == SZ(S));

        vi x(N), y(N);
        for (int i = 0; i < N; i++)
        {
            if (swapped)
                swap(S[i].x, S[i].y);
            x[S[i].id] = S[i].x;
            y[S[i].id] = S[i].y;
        }

        if (swapped)
            swap(W, L);
        for (int i = 0; i < N; i++)
        {
            const student &s = S[i];
            assert(s.x >= -s.r && s.x <= W + s.r);
            assert(s.y >= -s.r && s.y <= L + s.r);
            for (int j = i + 1; j < N; j++)
            {
                const student &t = S[j];
                bool cut = true;
                if (s.x + s.r <= t.x - t.r) cut = false;
                if (t.x + t.r <= s.x - s.r) cut = false;
                if (s.y + s.r <= t.y - t.r) cut = false;
                if (t.y + t.r <= s.y - s.r) cut = false;
                assert(!cut);
            }
        }

        printf("Case #%d:", cas + 1);
        for (int i = 0; i < N; i++)
            cout << ' ' << x[i] << ' ' << y[i];
        cout << '\n';
    }
    return 0;
}
