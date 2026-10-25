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

#define FN "D-small-attempt0"
#define N 64

//#define N 11000
int n,m;
vector<string> a;
vector<string> mark;

void dfs(int x, int y) {
	if (mark[x][y] == '*' || a[x][y] == '#') return;
	mark[x][y] = '*';
	dfs(x,y+1);
	dfs(x,y-1);
	dfs(x-1,y);
}

const int dx[3] = {1,0,0};
const int dy[3] = {0,-1,1};

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"*");

		scanf("%d%d",&n,&m);
		a.assign(n,"");
		REP(i,n) REP(j,m) {
			char c;
			do c = getc(stdin); while (!isdigit(c)&&c!='#'&&c!='.');
			a[i]+=c;
		}

		printf("Case #%d:\n",test);
		REP(dig,10) REP(is,n) REP(js,m) if (a[is][js] == '0'+dig) {
			mark.assign(n,string(m,'.'));
			dfs(is,js);
			int cnt = 0;
			REP(i,n) REP(j,m) if (mark[i][j] == '*') ++cnt;

			vector<string> need(n,string(m,'.'));
			need[is][js] = '*';

			queue<vector<string> > q;
			set<vector<string> > seen;

			q.push(mark);
			seen.insert(mark);
			bool cool = false;
			while (!q.empty()) {
				vector<string> s = q.front();
				q.pop();
				if (s==need) {
					break;
				}
				REP(dir,3) {
					vector<string> ss(n,string(m,'.'));
					REP(i,n) REP(j,m) if (s[i][j] == '*') {
						int x = i+dx[dir];
						int y = j+dy[dir];
						if (a[x][y] != '#')
						{
							if (x > is) goto bad;
							ss[x][y] = '*';
						}
						else
						{
							ss[i][j] = '*';
						}
					}
					if (!seen.count(ss)) {
						seen.insert(ss);
						q.push(ss);
					}
					bad:;
				}
			}
			printf("%d: %d %s\n",dig,cnt,seen.count(need)?"Lucky":"Unlucky");
		}

	}
	return 0;
}