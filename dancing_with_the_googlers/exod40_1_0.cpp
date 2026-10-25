#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n , s , p;
int a[1 << 7];
int dp[128][128];

void read() {
	int i;
	
	scanf ( "%d%d%d" , &n , &s , &p );
	for (i = 1; i <= n; i++) {
		scanf ( "%d" , &a[i] );
	}
}

int go ( int x , int y ) {
	if ( x > n ) {
		if ( !y ) return 0;
		return -10000;
	}
	
	int &ans = dp[x][y];
	if ( ans != -1 ) return ans;
	
	ans = 0;
	
	int i , j , k;
	
	for (i = 0; i <= 10; i++) {
		for (j = i; j <= i + 2 && j <= 10; j++) {
			for (k = j; k <= i + 2 && k <= 10; k++) {
				if ( i + j + k == a[x] ) {
					if ( k - i < 2 ) {
						ans = max ( ans , go ( x + 1 , y ) + (k >= p) );
					} else {
						if ( y ) {
							ans = max ( ans , go ( x + 1 , y - 1 ) + (k >= p) );
						}
					}
				}
			}
		}
	}
	
	return ans;
}

void solve() {
	memset ( dp , -1 , sizeof dp );
	printf ( "%d\n" , go ( 1 , s ) );
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
