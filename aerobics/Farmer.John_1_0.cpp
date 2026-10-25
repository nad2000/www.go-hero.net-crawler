#include<iostream>
#include<stdio.h>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=10002;
int ca,ti,i,n,r[maxn],j,w,l,x[maxn],y[maxn],wh[maxn];
bool work(int a,int b){
	int i=1,now=-1;
	while(i<=n){
		if(now<0)
			now=r[i];
		else
			now+=r[i]*2;
		x[i]=now-r[i];
		y[i]=0;
		if(x[i]>a)
			return false;
		i++;
		while(i<=n&&r[i]+y[i-1]+r[i-1]<=b){
			x[i]=x[i-1];
			y[i]=y[i-1]+r[i]+r[i-1];
			i++;
		}
	}
	return true;
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>n>>w>>l;
		fr(i,1,n){
			cin>>r[i];
			wh[i]=i;
		}
		fr(i,1,n)
			fr(j,i+1,n)
				if(r[i]<r[j]){
					swap(r[i],r[j]);
					swap(wh[i],wh[j]);
				}
		cout<<"Case #"<<ti<<":";
		if(work(w,l)){
			fr(i,1,n)
				fr(j,1,n)
					if(wh[j]==i)
						cout<<" "<<x[j]<<" "<<y[j];
			cout<<endl;
		}
		else{
			work(l,w);
			fr(i,1,n)
				fr(j,1,n)
					if(wh[j]==i)
						cout<<" "<<y[j]<<" "<<x[j];
			cout<<endl;
		}
	}
}