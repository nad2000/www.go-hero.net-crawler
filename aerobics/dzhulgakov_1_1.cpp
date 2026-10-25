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

#define FN "B-large"
//#define FN "b"

#define N 2048
#define SIDE 1000000
int n,w,h,rad[N];
PII r[N];
PII ans[N];
int id;

/*void fill1(int x1, int y1, int x2, int y2, bool hfirst=false) {
	if (id == n) return;
	int x = max(x1 + r[id].first, 0);
	int y = max(y1 + r[id].first, 0);
	int rr = r[id].first;
	if (x > w || y > h) return;
	if (x+r[id].first > x2 || y+r[id].first > y2) return;
	ans[r[id].second] = PII(x,y);
	++id;
//	if (hfirst) {
	fill1(x1,y+rr,x2,y2,!hfirst);
	fill1(x+rr,y-rr,x2,y+rr,!hfirst);
}

void fill2(int x1, int y1, int x2, int y2, bool hfirst=false) {
	if (id == n) return;
	int x = max(x1 + r[id].first, 0);
	int y = max(y1 + r[id].first, 0);
	int rr = r[id].first;
	if (x > w || y > h) return;
	if (x+r[id].first > x2 || y+r[id].first > y2) return;
	ans[r[id].second] = PII(x,y);
	++id;
//	if (hfirst) {
	fill2(x+rr,y-rr,x2,y+rr,!hfirst);
	fill2(x1,y+rr,x2,y2,!hfirst);
}*/

bool rec(int id, VPII pnts) {
	if (id == n)
		return true;
	REP(i,SZ(pnts)) {
		int x = max(pnts[i].X + r[id].first, 0);
		int y = max(pnts[i].Y + r[id].first, 0);
		if (x > w || y > h) continue;
		REP(jj,id) {
			int j = r[jj].second;
			int x1 = max(x-r[id].first,ans[j].X-rad[j]);
			int x2 = min(x+r[id].first,ans[j].X+rad[j]);

			int y1 = max(y-r[id].first,ans[j].Y-rad[j]);
			int y2 = min(y+r[id].first,ans[j].Y+rad[j]);
			if (x1 < x2 && y1 < y2)
				goto bad;
		}
		ans[r[id].second] = PII(x,y);

		{
			VPII pp = pnts;
			pp.erase(pp.begin()+i);
			pp.pb(PII(x+r[id].first,y-r[id].first));
			pp.pb(PII(x-r[id].first,y+r[id].first));
			if (rec(id+1,pp)) return true;
		}

		bad:;
	}
	return false;
}

void check() {
	REP(i,n) {
		if (ans[i].X < 0 || ans[i].X > w)
			fprintf(stderr,"X bad %d\n",i);
		if (ans[i].Y < 0 || ans[i].Y > h)
			fprintf(stderr,"Y bad %d\n",i);
	}
	REP(i,n) REP(j,i) {
		int x1 = max(ans[i].X-rad[i],ans[j].X-rad[j]);
		int x2 = min(ans[i].X+rad[i],ans[j].X+rad[j]);

		int y1 = max(ans[i].Y-rad[i],ans[j].Y-rad[j]);
		int y2 = min(ans[i].Y+rad[i],ans[j].Y+rad[j]);

		if (x1 < x2 && y1 < y2)
			fprintf(stderr,"inter %d %d\n",i,j);
	}
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
		scanf("%d%d%d",&n,&w,&h);
		REP(i,n) {
			scanf("%d",&r[i].first);
			r[i].second = i;
			rad[i]=r[i].first;
		}
		sort(r,r+n,greater<PII>());
		/*REP(step,1000) {
			id = 0; fill1(-SIDE,-SIDE,SIDE,SIDE);
			if (id == n) goto ok;
			id = 0; fill2(-SIDE,-SIDE,SIDE,SIDE);
			if (id == n) goto ok; 
			random_shuffle(r,r+n);
		}
		fprintf(stderr,"BAD!\n");
		ok:;*/
		if (!rec(0,VPII(1,PII(-SIDE,-SIDE))))
			fprintf(stderr,"BAD!\n");
		printf("Case #%d:",test);
		REP(i,n) printf(" %d.0 %d.0",ans[i].X,ans[i].Y);
		printf("\n");
		check();
	}
	return 0;
}