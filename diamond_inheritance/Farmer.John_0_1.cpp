#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=1002;
bool g[maxn][maxn];
vector<int> lst[maxn];
int ti,i,n,j,k,a,b,ca;
int main(){
	freopen("a1.in","r",stdin);
	freopen("a1.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>n;
		memset(g,0,sizeof(g));
		fr(i,1,n)
			g[i][i]=true;
		fr(i,1,n){
			cin>>k;
			lst[i].clear();
			while(k--){
				cin>>j;
				lst[i].push_back(j);
				g[i][j]=true;
			}
		}
		fr(k,1,n)
			fr(i,1,n)
				fr(j,1,n)
					g[i][j]|=(g[i][k]&&g[k][j]);
		bool ok=false;
		fr(i,1,n)
			fr(j,1,n){
				if(i==j)
					continue;
				k=lst[i].size();
				fr(a,0,k-2)
					fr(b,a+1,k-1)
						if(lst[i][a]!=lst[i][b]&&g[lst[i][a]][j]&&g[lst[i][b]][j])
							ok=true;
				if(ok)
					break;
			}
		if(ok)
			cout<<"Case #"<<ti<<": Yes"<<endl;
		else
			cout<<"Case #"<<ti<<": No"<<endl;
	}
}