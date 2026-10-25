#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#define fr(i,a,b) for(i=a;i<=b;++i)
#define ll long long
using namespace std;
const int maxn=102;
ll i,j,f[maxn][maxn],a[maxn],b[maxn],A[maxn],B[maxn],n,m,ti,ca,k,l,sum,tot;
int main(){
	FILE *inf=freopen("c1.in","r",stdin);
	FILE *ouf=freopen("c1.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		memset(f,0,sizeof(f));
		cin>>n>>m;
		fr(i,1,n)
			cin>>a[i]>>A[i];
		fr(i,1,m)
			cin>>b[i]>>B[i];
		fr(i,1,n)
			fr(j,1,m){
				f[i][j]=max(f[i-1][j],f[i][j-1]);
				if(A[i]==B[j]){
					sum=0;
					for(k=i;k>=1;k--){
						if(A[k]==B[j])
							sum+=a[k];
						tot=0;
						for(l=j;l>=1;l--){
							if(B[l]==A[i])
								tot+=b[l];
							f[i][j]=max(f[i][j],f[k-1][l-1]+min(sum,tot));
						}
					}
				}
			}
		cout<<"Case #"<<ti<<": "<<f[n][m]<<endl;
	}
	fclose(inf);
	fclose(ouf);	
}