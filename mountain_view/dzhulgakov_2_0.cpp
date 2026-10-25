#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define FN "C-small-attempt0"

//#define N 11000
int n;
int a[2048];
LL h[2048];

/*void go(int s, int e) {
	if (s>e) return;
	if (s==e) {
		h[s] = 0;
		return;
	}
	if (a[s])
	go(s+1,a[s]-1);
	go(a[s],e);
	double d = 0;
	FOR(i,a[s]+1,e) {
		d = max(d, (h[i]/(double)(i-s) - h[a[s]]/(double)(a[s]-s)) / ( 1.0/(a[s]-s) - 1.0/(i-s) ));
	}
	LL dd = ceil(d)+1;
	FOR(i,a[s],e) h[i] += dd;

	LL mx = 0;
	FOR(i,s+1,a[s]-1) mx = max(h[i],mx);
	FOR(i,s+1,a[s]-1) h[i] -= mx+1;
}*/

typedef vector<double> VD;

namespace SimplexMethod {
const double EPS = 1.0E-12;
vector<VD> a; VD b, c, res;
VI N, kt; int m;
void pivot(int k, int s, int e) {
    int x = kt[s];
    double p = a[s][e];
    REP(i, k) a[s][i] /= p;
    b[s] /= p;
    N[e] = false;
    REP(i, m) if (i != s) {
        b[i] -= a[i][e] * b[s];
        a[i][x] = -a[i][e] * a[s][x]; }
    REP(j, k) if (N[j]) {
        c[j] -= c[e] * a[s][j];
        REP(i, m) if (i != s)
            a[i][j] -= a[i][e] * a[s][j]; }
    kt[s] = e;
    N[x] = true;
    c[x] = -c[e] * a[s][x]; }
VD doit(int k) {
    VD res;
    while (true) {
        int e = -1, s = -1;
        REP(i, k) if (N[i] && c[i] > EPS) {e = i; break; }
        if (e == -1) break;
        REP(i, m) if (a[i][e] > EPS && (s == -1 || b[i] / a[i][e] < b[s] / a[s][e])) s = i;
        if (s == -1) return VD(); // unbounded
        pivot(k, s, e); }
    res.resize(k, 0);
    REP(i, m) res[kt[i]] = b[i];
    return res; }
// max c * x, while A * x <= b, x >= 0, для других знаков неравенства нужно вводить доп.переменные
VD simplex(vector<VD> _A, VD _b, VD _c) { a=_A; b=_b; c=_c;
    m = SZ(a);
    int n = SZ(a[0]); int k = n + m + 1;
    c.resize(n + m); kt.resize(m);
    N = VI(k, true);
    REP(i, m) {
        a[i].resize(k);
        a[i][n + i] =  1;
        a[i][k - 1] = -1;
        kt[i] = n + i;
        N[kt[i]] = false; }
    int s = min_element(ALL(b)) - b.begin();
    if (b[s] < -EPS) {
        c = VD(k, 0);
        c[k - 1] = -1;
        pivot(k, s, k - 1);
        res = doit(k);
        if (res[k - 1] > EPS) return VD(); // infeasible
        REP(i, m) if (kt[i] == k - 1) REP(j, k-1)
            if (N[j] && (a[i][j] < -EPS || EPS < a[i][j])) {
                pivot(k, i, j); break; }
        c = _c; c.resize(k, 0);
        REP(i, m) REP(j, k) if (N[j])
            c[j] -= c[kt[i]] * a[i][j]; }
    res = doit(k - 1);
    if (!res.empty()) res.resize(n);
    return res; }
}

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"*");

		scanf("%d",&n);
		REP(i,n-1) scanf("%d",a+i),a[i]--;

		/*go(0,n-1);
		LL mn = 0;
		REP(i,n) mn = min(mn, h[i]);
		REP(i,n) h[i]-=mn-1;*/
		vector<VD> A;
		VD B,C;
		REP(i,n-1)
		{
			REP(j,n) if (j>i&&j!=a[i]) {
				A.pb(VD(n,0.0));
				B.pb(0);
				A.back()[j] += 1.0;
				A.back()[i] -= (a[i]-j)/(double)(a[i]-i);
				A.back()[a[i]] -= (j-i)/(double)(a[i]-i);
				//if (j>a[i]) REP(tt,n) A.back()[tt] *= -1.0;
				B.back() = -1;
			}
		}
		printf("Case #%d: ",test);
		C.assign(n,-1.0);
		VD r;
		if (n==2)
			r.assign(2,0);
		else
			r = SimplexMethod::simplex(A,B,C);
		if (r.empty()) {
			printf("Impossible\n");
		} else {
			double mn = *min_element(ALL(r));
			REP(i,n) {
				printf(" %d"+(i==0),(int)((r[i]-mn+1000)*1000));
			}
			printf("\n");
		}
	}
	return 0;
}