#include<iostream>
#include<stdio.h>
#include<string.h>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=102;
int ti,ca,i,j,n,s,p,x[maxn],f[maxn][maxn];
int main(){
	freopen("b2.in","r",stdin);
	freopen("b2.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>n>>s>>p;
		fr(i,1,n)
			cin>>x[i];
		memset(f,200,sizeof(f));
		f[0][0]=0;
		fr(i,1,n)
			fr(j,0,s){
				f[i][j]=f[i-1][j]+((x[i]+2)/3>=p);
				if(j&&x[i]>=2)
					f[i][j]=max(f[i][j],f[i-1][j-1]+((x[i]-2)/3+2>=p));
			}
		cout<<"Case #"<<ti<<": "<<f[n][s]<<endl;
	}
}