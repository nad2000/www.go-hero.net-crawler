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

static ll div_up(ll a, ll b)
{
    assert(b > 0);
    if (a > 0)
        return (a + b - 1) / b;
    else
        return a / b;
}

static ll div_down(ll a, ll b)
{
    assert(b > 0);
    return -div_up(-a, b);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int N;
        cin >> N;
        vector<int> top(N - 1);
        vector<ll> y(N);
        for (int i = 0; i < N - 1; i++)
        {
            cin >> top[i];
            top[i]--;
        }

        vector<int> hull;
        hull.push_back(N - 1);
        y[N - 1] = 500000000;
        for (int i = N - 2; i >= 0; i--)
        {
            ll lo = 0, hi = 1000000000;
            while (top[i] > hull.back())
            {
                assert(hull.size() >= 2);
                ll x1 = hull[hull.size() - 2];
                ll x0 = hull[hull.size() - 1];
                ll dy = y[x1] - y[x0];
                ll dx = x1 - x0;
                lo = max(lo, y[x0] + div_down(dy * (i - x0), dx) + 1);
                hull.pop_back();
            }
            if (top[i] != hull.back())
                goto impossible;
            if (hull.size() == 1)
                y[i] = max(lo, y[hull.back()]);
            else
            {
                ll x1 = hull[hull.size() - 2];
                ll x0 = hull[hull.size() - 1];
                ll dy = y[x1] - y[x0];
                ll dx = x1 - x0;
                hi = min(hi, y[x0] + div_up(dy * (i - x0), dx) - 1);

                assert(lo <= hi);
                y[i] = (hi * 10000 + lo) / 10001;
            }
            hull.push_back(i);
        }
        printf("Case #%d:", cas + 1);
        for (int i = 0; i < N; i++)
            cout << ' ' << y[i];
        cout << '\n';
        continue;

impossible:
        printf("Case #%d: Impossible\n", cas + 1);
    }
    return 0;
}
