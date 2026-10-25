#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string t = "oieastbg";

int k;
string a;
int f[64][64];
int in[64] , out[64];

void read() {
	char buf[1024];
	scanf ( "%d%s" , &k , buf ); a = string ( buf );
}

void add ( int x , int y ) {
	f[x][y] = 1;
}

int get ( char x ) {
	int i;
	
	for (i = 0; i < (int)t.size(); i++) {
		if ( t[i] == x ) {
			return 26 + i;
		}
	}
	
	return 0;
}

void solve() {
	int i , j;
	int ans = 0 , t = 0;
	
	memset ( f , 0 , sizeof f );
	memset ( in , 0 , sizeof in );
	memset ( out , 0 , sizeof out );
	
	for (i = 0; i + 1 < (int)a.size(); i++) {
		add ( a[i] - 'a' , a[i + 1] - 'a' );
		if ( get ( a[i] ) ) add ( get ( a[i] ) , a[i + 1] - 'a' );
		if ( get ( a[i + 1] ) ) add ( a[i] - 'a' , get ( a[i + 1] ) );
		if ( get ( a[i] ) && get ( a[i + 1] ) ) add ( get ( a[i] ) , get ( a[i + 1] ) );
	}
	
	for (i = 0; i < 40; i++) {
		for (j = 0; j < 40; j++) {
			in[j] += f[i][j];
			out[i] += f[i][j];
			ans += f[i][j];
		}
	}
	
	for (i = 0; i < 40; i++) {
		t += max ( 0 , out[i] - in[i] );
	}
	
	if ( t == 0 ) ++ ans;
	else ans += t;
	
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
