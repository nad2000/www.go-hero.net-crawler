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

void alg() {
    int n_googlers;
    int n_surprising;
    int p;
    cin >> n_googlers >> n_surprising >> p;
    int result = 0;
    for (int i = 0; i < n_googlers; ++i) {
        int total;
        cin >> total;
        bool is = false, may = false;
        for (int a = 0; a <= 10; ++a) {
            for (int b = a; b <= 10; ++b) {
                for (int c = b; c <= 10; ++c) {
                    if (a + b + c == total && c >= p) {
                        if (c - a <= 1) {
                            is = true;
                        } else if (c - a <= 2) {
                            may = true;
                        }
                    }
                }
            }
        }
        if (!is && may && n_surprising > 0) {
            --n_surprising;
            is = true;
        }
        result += is;
    }
    static int caseNo = 0;
    cout << "Case #" << ++caseNo << ": " << result << endl;
}

int main() {
    int nCases;
    cin >> nCases;

    for (int i = 0; i < nCases; ++i) {
        alg();
    }
}
