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

int p10;

int next(int x) {
    return x / 10 + (x % 10) * p10;
}

void alg() {
    p10 = 1;
    int a, b;
    scanf("%d %d", &a, &b);
    while (p10 * 10 <= a) {
        p10 *= 10;
    }
    int result = 0;
    for (int i = a; i <= b; ++i) {
        int j = next(i);
        while (j != i) {
            if (a <= j && j <= b && j < i) {
                ++result;
            }
            j = next(j);
        }
    }
    static int caseNo = 0;
    printf("Case #%d: %d\n", ++caseNo, result);
}

int main() {
    int d;
    scanf("%d", &d);
    while (d--) {
        alg();
    }
}
