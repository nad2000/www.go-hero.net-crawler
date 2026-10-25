#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m , f , n;
pair < int , int > p[256];
int dp[1 << 22];

void read() {
	int i;
	
	scanf ( "%d%d%d" , &m , &f , &n );
	for (i = 1; i <= n; i++) {
		scanf ( "%d%d" , &p[i].second , &p[i].first );
	}
}

int go ( int x ) {
	printf ( " -- %d\n " , x );
	int begx = x;
	int &ans = dp[x];
	if ( ans != -1 ) return ans;
	
	ans = 0;
	int i , cnt = 0 , last = 0;
	
	x -= f;
	if ( x <= 0 ) return ans = 0;
	
	for (i = 1; i <= n; i++) {
		if ( x <= 0 ) break;
		
		cnt = min ( x / p[i].second , p[i].first - last ) * p[i].second;
		ans = max ( ans , last + go ( x - cnt ) + min ( x / p[i].second , p[i].first - last ) );
		
		x -= (p[i].first - last) * p[i].second;
		last = p[i].first;
	}
	
	
	return ans;
}

void solve() {
	int i , j;
	
	sort ( p + 1 , p + n + 1 );
	
	for (i = n; i > 1; i--) {
		if ( p[i - 1].second > p[i].second ) {
			p[i - 1].second = p[i].second;
		}
		++ p[i].first;
	}
	++ p[1].first;
	
	memset ( dp , -1 , sizeof dp );
	
	for (j = 0; j <= m; j++) {
		dp[j] = 0;
		
		int x = j , cnt = 0 , last = 0;
		
		x -= f;
		if ( x < 0 ) continue;
		
		for (i = 1; i <= n; i++) {
			if ( x <= 0 ) break;
		
			cnt = min ( x / p[i].second , p[i].first - last ) * p[i].second;
			dp[j] = max ( dp[j] , last + dp[ x - cnt ] + min ( x / p[i].second , p[i].first - last ) );
		
			x -= (p[i].first - last) * p[i].second;
			last = p[i].first;
		}
	}

	printf ( "%d\n" , dp[m] );
	fflush ( stdout );
}

int main() {
	int i , cases;
	
	scanf ( "%d" , &cases );
	for (i = 1; i <= cases; i++) {
		read();
		printf ( "Case #%d: " , i );
		solve();
	}
	
	return 0;
}
