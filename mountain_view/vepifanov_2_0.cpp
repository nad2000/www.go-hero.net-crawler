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
int m;
vi v[2000];
int p[2000], y[2000];

int go (int x, int dx, int dy) {
	if (sz (v[x]) == 0) re 0;
	sort (all (v[x]));
	for (int i = 0; i < sz (v[x]); i++) {
		int j = v[x][i];
		y[j] = (y[x] - (dy * (x - j)) / dx - 1);
		go (j, x - j, y[x] - y[j]);
		dx = x - j;
		dy = y[x] - y[j];
	}
	re 0;
}

ll vect (ll x1, ll y1, ll x2, ll y2) {
	re x1 * y2 - x2 * y1;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

		scanf ("%d", &n);
		for (int i = 0; i < n; i++) v[i].clear ();
		for (int i = 0; i + 1 < n; i++) {
			scanf ("%d", &p[i]);
			p[i]--;
			v[p[i]].pb (i);
		}

		int ok = 1;
		for (int i = 0; i + 1 < n && ok; i++) {
			if (p[i] <= i) { ok = 0; break; }
			for (int j = i + 1; j < p[i]; j++)
				if (p[j] > p[i]) {
					ok = 0;
					break;
				}
		}

		
		cout << "Case #" << it << ": ";

		if (!ok) printf ("Impossible"); else {
			y[n - 1] = 0;
			go (n - 1, 1, 0);
			int t = 0;
			for (int i = 0; i < n; i++) t = max (t, -y[i]);
			for (int i = 0; i < n; i++) printf ("%d ", y[i] + t);
			int ok = 1;
			for (int i = 0; i < n; i++)
				if (y[i] + t > 1000000000)
					ok = 0;
			for (int i = 0; i + 1 < n; i++) {
				int k = i + 1;
				for (int j = i + 2; j < n; j++)
					if (vect (j - i, y[j] - y[i], k - i, y[k] - y[i]) < 0)
						k = j;
				if (p[i] != k) ok = 0;
			}
			if (!ok) cerr << it << " bad" << endl;
		}

		cout << endl;
	}
	return 0;
}