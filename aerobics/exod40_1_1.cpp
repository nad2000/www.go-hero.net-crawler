#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
double w , l;
pair < double , int > r[1024];

double x2[1024] , y2[1024];
double x[1024] , y[1024];

void read() {
	int i;
	
	scanf ( "%d%lf%lf" , &n , &w , &l );
	for (i = 1; i <= n; i++) {
		scanf ( "%lf" , &r[i].first );
		r[i].second = i;
		
		x[i] = y[i] = -1;
	}
}

inline double getDRand ( double x ) {
	long long t = 0;
	double s;
	int i;
	
	for (i = 0; i < 60; i++) {
		t = (t << 1) | (rand() & 1);
	}
	
	s = (double)(t % ((long long)x * 1000LL));
	
	return s / 1000;
}

void move ( int i ) {
	x[i] = getDRand ( w );
	y[i] = getDRand ( l );
}

void solve() {
	int i , j;
	double curx , cury , nextx;
	
	sort ( r + 1 , r + n + 1 );
	reverse ( r + 1 , r + n + 1 );
	
	curx = cury = 0;
	nextx = 0;
	
	for (i = 1; i <= n; i++) {
		x[i] = curx;
		y[i] = cury;
		
		cury += r[i].first;
		nextx = max ( nextx , curx + r[i].first );
		
		if ( i != n ) {
			cury += r[i + 1].first;
		
			if ( cury > l ) {
				curx = nextx + r[i + 1].first;
				cury = 0;
			}
		}
	}
	
	do {
	int ch = 0;
		for (i = 1; i <= n; i++) {
			if ( x[i] < -1e-9 || x[i] > w + 1e-9 || y[i] < -1e-9 || y[i] > l + 1e-9 ) {
				move ( i );	
				ch = 1;
			}
		}
		
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if ( i == j ) continue;
				
				if ( sqrt ( (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) ) < (r[i].first + r[j].first) - 1e-9 ) {
					if ( r[i] < r[j] ) {
						move ( i );
					} else {
						move ( j );
					}
					ch = 1;
				}
			}
		}
	if ( !ch ) break;
	} while ( 1 );
	
	for (i = 1; i <= n; i++) {
		if ( x[i] < -1e-9 || x[i] > w + 1e-9 || y[i] < -1e-9 || y[i] > l + 1e-9 ) {
			printf (  "here\n" );
		}
	}
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if ( i == j ) continue;
			
			if ( sqrt ( (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) ) < (r[i].first + r[j].first) - 1e-9 ) {
				printf ( "fail\n" );
			}
		}
	}
	
	for (i = 1; i <= n; i++) {
		x2[ r[i].second ] = x[i];
		y2[ r[i].second ] = y[i];
	}
	
	for (i = 1; i <= n; i++) {
		printf ( " %.9lf %.9lf" , x2[i] , y2[i] );
	}
	printf ( "\n" );
	fflush ( stdout );
}

int main() {
	int i , cases;
	
	scanf ( "%d" , &cases );
	for (i = 1; i <= cases; i++) {
		read();
		printf ( "Case #%d:" , i );
		solve();
// 		break;
	}
	
	return 0;
}
