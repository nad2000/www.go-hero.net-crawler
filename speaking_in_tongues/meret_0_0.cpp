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

string sampleIn[] = {
        "ejp mysljylc kd kxveddknmc re jsicpdrysi",
        "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
        "de kr kd eoya kw aej tysr re ujdr lkgc jv",
        "yeq"
        };

string sampleOut[] = {
        "our language is impossible to understand",
        "there are twenty six factorial possibilities",
        "so it is okay if you want to just give up",
        "aoz"
        };

int main() {
    map<char, char> mapped;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < (int) sampleIn[i].length(); ++j) {
            mapped[sampleIn[i][j]] = sampleOut[i][j];
        }
    }
    set<char> got;
    FORE (it, mapped) {
        got.insert(it->ND);
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        if (mapped.find(i) == mapped.end()) {
            for (char j = 'a'; j <= 'z'; ++j) {
                if (got.find(j) == got.end()) {
                    mapped[i] = j;
                    got.insert(j);
                    break;
                }
            }
        }
    }
    assert(mapped.size() == 27);
    int nCases;
    cin >> nCases;
    string s;
    getline(cin, s);
    for (int caseNo = 1; caseNo <= nCases; ++caseNo) {
        getline(cin, s);
        FORE (it, s) {
            *it = mapped[*it];
        }
        cout << "Case #" << caseNo << ": " << s << endl;
    }
}
