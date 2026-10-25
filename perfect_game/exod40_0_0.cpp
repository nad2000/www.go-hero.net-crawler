#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1 << 10;

int n;
int l[MAXN] , p[MAXN];
pair < int , int > a[MAXN];

void read() {
	int i;
	
	scanf ( "%d" , &n );
	for (i = 1; i <= n; i++) scanf ( "%d" , &l[i] );
	for (i = 1; i <= n; i++) scanf ( "%d" , &p[i] );
}

void solve() {
	int i;
	
	for (i = 1; i <= n; i++) {
		a[i].first = -p[i];
		a[i].second = i;
	}
	
	sort ( a + 1 , a + n + 1 );
	for (i = 1; i <= n; i++) {
		printf ( "%d%c" , a[i].second - 1 , (i == n) ? '\n' : ' ' );
	}
}

int main() {
	int cases , i;
	
	scanf ( "%d" , &cases );
	for (i = 1; i <= cases; i++) {
		read();
		printf ( "Case #%d: " , i );
		solve();
	}
	
	return 0;
}
