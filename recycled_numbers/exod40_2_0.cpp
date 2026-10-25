#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

int a , b;
int c[32];

set < int > st;

void read() {
	scanf ( "%d%d" , &a , &b );
}

void solve() {
	int ans = 0;
	int i , j , k , x;
	int n;
	
	for (i = a; i <= b; i++) {
		x = i;
		
		for (j = 0; x; j++) {
			c[j] = x % 10;
			x /= 10;
		}
		n = j;
		
		st.clear();
		
		for (j = 0; j + 1 < n; j++) {
			if ( c[j] == 0 ) continue;
			x = 0;
			
			for (k = j; k >= 0; k--) {
				x = x * 10 + c[k];
			}
			for (k = n - 1; k > j; k--) {
				x = x * 10 + c[k];
			}
			
			if ( x > i && x <= b && st.count ( x ) == 0 ) {
				st.insert ( x );
				++ ans;
			}
		}
	}
	
	printf ( "%d\n" , ans );
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
