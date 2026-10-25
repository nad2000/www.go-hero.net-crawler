#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000000;

int n;
int a[1 << 11];
int ans[1 << 11];

vector < pair < int , int > > st;

void read() {
	int i;
	
	scanf ( "%d" , &n );
	for (i = 1; i < n; i++) {
		ans[i] = 0;
		scanf ( "%d" , &a[i] );
	}
}

void solve() {
	int i , l , r , mid;
	
	st.clear();
	
	for (i = 1; i < n; i++) {
		while ( (int)st.size() && st.back().first <= i ) st.pop_back();
		
		if ( (int)st.size() == 0 ) {
			ans[ a[i] ] = MAX;
			st.push_back ( make_pair ( a[i] , i ) );
		} else {
			
			
			if ( st.back().first == a[i] ) {
				st.back().second = i;
			} else {
				l = 0;
				r = MAX + 1;
				
				while ( l < r ) {
					mid = l + (r - l) / 2;
					
					/*
					 mid / (a[i] - i) > ans[st.back().first] / (st.back().first - i)
					 */
					
					if ( (long long)(mid - ans[i]) * (long long)(st.back().first - i) 
							> (long long)(ans[ st.back().first ] - ans[i]) * (long long)(a[i] - i) ) {
						r = mid;
					} else {
						l = mid + 1;
					}
				}
				
				if ( l > MAX ) {
					printf ( "Impossible\n" );
					return ;
				}
				
				ans[ a[i] ] = l;
				st.push_back ( make_pair ( a[i] , i ) );
			}
		}
	}
	
	int j;
	int bidx;
	
	for (i = 1; i < n; i++) {
		bidx = i + 1;
		
		for (j = i + 2; j <= n; j++) {
			if ( (long long)(ans[j] - ans[i]) * (long long)(bidx - i) 
						> (long long)(ans[bidx] - ans[i]) * (long long)(j - i) ) {
				bidx = j;
			}
		}
		
		if ( a[i] != bidx ) {
			printf ( "here\n" );
			printf ( "Impossible\n" );
			return ;
		}
	}
	
	for (i = 1; i <= n; i++) {
		printf ( "%d" , ans[i] );
		printf ( "%c" , (i == n) ? '\n' : ' ' );
	}
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
