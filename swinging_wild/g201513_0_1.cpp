#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int ntest;
int n, d[20000], l[20000];
int u[20000];

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d%d", &d[i], &l[i]);
		}
		scanf("%d", &d[n]); l[n] = 0;
		memset(u, -1, sizeof(u));
		u[0] = min(d[0], l[0]);

		for(int i=0; i<n; i++) {

			if(u[i] < 0) continue;

			for(int j=i+1; j<=n; j++) {
				if(d[j] > d[i] + u[i]) break;

				u[j] = max(u[j], d[j]-d[i]);
				u[j] = min(u[j], l[j]);
			}
		}

		printf("Case #%d: %s\n", test, u[n]<0?"NO":"YES");
	}
	return 0;
}