#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m, w, h;

ii v[1001];
int x[1001], y1[1001], y2[1001];
int rx[1001], ry[1001];

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%d%d", &n, &w, &h);
		for (int i = 0; i < n; i++) {
			scanf ("%d", &v[i].fi);
			v[i].se = i;
		}

		sort (v, v + n);
		reverse (v, v + n);
		int r = 1;
		x[0] = -2e9;
		y1[0] = -2e9;
		y2[0] = 2e9;
		for (int i = 0; i < n; i++) {
			int R = v[i].fi;
			int t = v[i].se;
			int ok = 0;
			for (int j = 0; j < r; j++) {
				int cx = max (0, x[j] + R);
				int cy = max (0, y1[j] + R);
				if (cx <= w && cy <= h && cy + R <= y2[j]) {
					rx[t] = cx;
					ry[t] = cy;
					y1[j] = cy + R;
					x[r] = cx + R;
					y1[r] = cy - R;
					y2[r] = cy + R;
					r++;
					ok = 1;
					break;
				}
			}
			if (!ok) cerr << "BAD" << endl;
		}
		
		cout << "Case #" << it << ": ";
		for (int i = 0; i < n; i++) printf ("%d %d ", rx[i], ry[i]);

		cout << endl;
	}
	return 0;
}