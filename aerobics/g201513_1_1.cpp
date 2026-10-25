#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<assert.h>

using namespace std;

const int maxn = 20005;
const int inf = 1000000000;

int ntest;
int W, L, n;
pair<int, int> r[maxn];
int x[maxn], y[maxn];
int now, cnt;

int ansx[maxn], ansy[maxn];

bool inside(int X, int L, int R) {
	return L < X && X < R;
}

bool inside(int L1, int R1, int L2, int R2) {
	return inside(L1, L2, R2) || inside(R1, L2, R2)
		|| inside(L2, L1, R1) || inside(R2, L1, R1)
		|| (L1 == L2 && R1 == R2);
}

void put(int u, int v) {
	int miny = -u;
	if(now + u > W) now = -inf;
	if(now < -u) now = -u;
	for(int i=0; i<cnt; i++) {
		if(inside(now, now+u+u, x[i]-r[i].first, x[i]+r[i].first)) {
			miny = max(miny, y[i]+r[i].first);
		}
	}
	ansx[v] = x[cnt] = now + u;
	ansy[v] = y[cnt] = miny + u;

	assert(x[cnt] >= 0 && x[cnt] <= W);
	assert(y[cnt] >= 0 && y[cnt] <= L);

	cnt++;
	now += u+u;
	if(now > W) now = -inf;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large2.out", "w", stdout);

	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d%d%d", &n, &W, &L);
		for(int i=0; i<n; i++) {
			scanf("%d", &r[i].first);
			r[i].second = i;
		}

		sort(r, r+n);
		reverse(r, r+n);

		cnt = 0;

		now = -inf;
		for(int i=0; i<n; i++) {
			put(r[i].first, r[i].second);
		}

		printf("Case #%d:", test);
		for(int i=0; i<n; i++) printf(" %d.0 %d.0", ansx[i], ansy[i]);
		printf("\n");
	}
	return 0;
}