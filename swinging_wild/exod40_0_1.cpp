#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int x[1 << 17] , y[1 << 17];
int dp[1 << 17];
int d;

void read() {
	int i;
	
	scanf ( "%d" , &n );
	for (i = 1; i <= n; i++) {
		scanf ( "%d%d" , &x[i] , &y[i ]);
		dp[i] = -1;
	}
	scanf ( "%d" , &d );
}

int solve() {
	int i , j;
	
	dp[1] = 0;
	
	for (i = 1; i <= n; i++) {
		if ( dp[i] != -1 ) {
			for (j = i + 1; j <= n; j++) {
				if ( x[j] <= x[i] + min ( x[i] - dp[i] , y[i] ) ) {
					if ( dp[j] == -1 ) {
						dp[j] = x[i];
					}
				} else {
					break;
				}
			}
			
			if ( x[i] + min ( x[i] - dp[i] , y[i] ) >= d ) {
				return 1;
			}
		}
	}
	
	return 0;
}

int main() {
	int cases;
	int i = 1;
	
	scanf ( "%d" , &cases );
	while ( cases -- ) {
		read();
		printf ( "Case #%d: %s\n" , i ++ , solve() ? "YES" : "NO" );
	}
	
	return 0;
}
