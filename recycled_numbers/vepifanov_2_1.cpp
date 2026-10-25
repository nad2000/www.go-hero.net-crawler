#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;
int was[2000001];
int ct;

int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {

		scanf ("%d%d", &n, &m);
		int base = 1;
		while (base * 10 <= n) base *= 10;
		int ans = 0;
		for (int i = n; i <= m; i++) {
			ct++;
			int k = i;
			for (int j = 0; j < 10; j++) {
				if (k >= n && k <= m && k != i && was[k] != ct) {
					was[k] = ct;
					ans++;
				}
				k = k / 10 + (k % 10) * base;
			}
		}

		printf ("Case #%d: %d\n", it, ans / 2);
	}
	return 0;
}