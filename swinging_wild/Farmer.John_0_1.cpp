#include<iostream>
#include<stdio.h>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=10002;
int i,j,n,dis,ca,ti,ma[maxn],d[maxn],l[maxn];
bool ok;
int main(){
	freopen("a2.in","r",stdin);
	freopen("a2.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>n;
		fr(i,1,n){
			cin>>d[i]>>l[i];
			ma[i]=-1;
		}
		cin>>dis;
		ma[1]=d[1];
		fr(i,2,n)
			fr(j,1,i-1)
				if(d[i]-d[j]<=ma[j])
					ma[i]=max(ma[i],min(d[i]-d[j],l[i]));
		ok=false;
		fr(i,1,n){
//			cout<<d[i]<<" "<<ma[i]<<endl;
			if(d[i]+ma[i]>=dis)
				ok=true;
		}
		cout<<"Case #"<<ti<<": "<<(ok?"YES":"NO")<<endl;
	}
}