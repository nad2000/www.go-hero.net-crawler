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

const int N = 10005;

int n;

int pos[N];
int len[N];

int dp[N];

bool alg() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &pos[i], &len[i]);
    }
    int destination;
    scanf("%d", &destination);
    for (int i = 1; i <= n; ++i) {
        dp[i] = -1;
    }
    dp[1] = pos[1];
    for (int i = 1; i <= n; ++i) {
        if (pos[i] + dp[i] >= destination) {
            return true;
        }
        for (int j = i + 1; j <= n && pos[i] + dp[i] >= pos[j]; ++j) {
            dp[j] = max(dp[j], min(len[j], pos[j] - pos[i]));
        }
    }
    return false;
}

int main() {
    int n_cases;
    scanf("%d", &n_cases);
    for (int test_case = 1; test_case <= n_cases; ++test_case) {
        printf("Case #%d: %s\n", test_case, alg() ? "YES" : "NO");
    }
}
