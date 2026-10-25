#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int N = 2005;

int height[N];
int p[N];

int n;

void go(int l, int r, int slope) {
    int c = l;
    while (c != r) {
        height[c] = height[r] - slope * (r - c);
        if (p[c] > r) {
            throw false;
        }
        c = p[c];
    }
    c = l;
    while (c != r) {
        if (c + 1 != p[c]) {
            go(c + 1, p[c], slope + 1);
        }
        c = p[c];
    }
}

void alg() {
    scanf("%d", &n);
    for (int i  = 1; i < n; ++i) {
        scanf("%d", &p[i]);
    }
    height[n] = (int) 1e9;
    try {
        go(1, n, 0);
    } catch (...) {
        printf(" Impossible");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        printf(" %d", height[i]);
    }
}

int main() {
    int n_cases;
    scanf("%d", &n_cases);
    for (int i = 1; i <= n_cases; ++i) {
        printf("Case #%d:", i);
        alg();
        printf("\n");
    }
}
