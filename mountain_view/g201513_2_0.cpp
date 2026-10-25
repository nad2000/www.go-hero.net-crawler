#include<stdio.h>
#include<algorithm>

using namespace std;

const int inf = 1000000000;

int ntest;
int n;
int p[2005];
int a[2005];

int get(int X1, int Y1, int X2, int Y2, int X) {
	int DY = Y2 - Y1;
	int DX = X2 - X1;

	int Y = (1ll * (X - X1) * DY + 1ll * Y1 * DX - 1) / DX;

	return Y;
}

bool doit(int l, int r, int h, int rh) {
	
	if(l+1 > r-1) return true;

	for(int i=l+1; i<=r-1; i++) if(p[i] > r) return false;

	int pre = l;
	for(int i=l+1; i<=r-1; i++) if(p[i] == r) {
		a[i] = h-1;
		int u = get(i, h-1, r, rh, pre);
		if(!doit(pre, i, min(h-1, u), a[i])) return false;
		pre = i;
	}

	int u = get(pre, h-1, r, rh, pre);
	if(!doit(pre, r, min(h-1, u), rh)) return false;

	return true;
}

bool calc(int l, int r) {
	a[l] = inf; a[p[l]] = inf;
	if(!doit(l, p[l], inf, inf)) return false;
	if(p[l] != r) return calc(p[l], r);
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d", &n);
		for(int i=1; i<n; i++) scanf("%d", &p[i]);

		bool ok = calc(1, n);

		if(ok) {
			printf("Case #%d:", test);
			for(int i=1; i<=n; i++) printf(" %d", a[i]);
			printf("\n");
		} else {
			printf("Case #%d: Impossible\n", test);
		}
	}
	return 0;
}