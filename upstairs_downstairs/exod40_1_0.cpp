#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n , m;
double prob[10005];
int c[10005];

vector < double > all , cur;
double now;

void read() {
	int i , x , y;
	
	scanf ( "%d%d" , &n , &m );
	for (i = 1; i <= n; i++) {
		scanf ( "%d/%d %d" , &x , &y , &c[i] );
		prob[i] = (double)x / (double)y;
		
// 		printf ( "%lf\n" , prob[i] );
	}
}

void go ( int x , int y , double prob ) {
	if ( x == m ) {
		return;
	}
	
	if ( y == 0 ) {
		go ( x + 1 , 1 , prob * (1 - cur[x]) );
		go ( x + 1 , 0 , prob * cur[x] );
	} else {
		go ( x + 1 , 1 , prob * (1 - cur[x]) );
		now += prob * cur[x];
	}
}

void solve() {
	int i , j;
	double ans = 1;
	
	all.clear();
	for (i = 1; i <= n; i++) {
		while ( c[i] -- ) {
			all.push_back ( prob[i] );
		}
	}
	
	sort ( all.rbegin() , all.rend() );
	
	for (i = 0; i <= m; i++) {
		cur.clear();
		
		for (j = 0; j < i; j++) {
			cur.push_back ( all[j] );
		}
		
		for (j = 0; j < m - i; j++) {
			cur.push_back ( all[(int)all.size() - j - 1] );
		}
		
		sort ( cur.rbegin() , cur.rend() );
		/*
		for (j = 0; j < (int)cur.size(); j++) {
			printf ( "%lf " , cur[j] );
		}
		printf ( "\n" );
		*/
		now = 0;
		go ( 0 , 0 , 1 );
		
		if ( now < ans ) ans = now;
	}
	
	printf ( "%.9lf\n" , ans );
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
