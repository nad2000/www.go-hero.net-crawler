#include<iostream>
#include<stdio.h>
#define fr(i,a,b) for(i=a;i<=b;++i)
#define ll long long
using namespace std;
const int maxn=202;
ll ca,ti,m,f,n,p[maxn],s[maxn],newn,i,j,ans;
ll cal(ll r){
	ll left=m-r*f,tot=0,i,buy,add;
	fr(i,1,n){
		buy=left/p[i];
		if(buy==0)
			break;
		add=min(buy,(s[i]-s[i-1])*r);
		tot+=add;
		left-=p[i]*add;
	}
	return tot;		
}
int main(){
	freopen("c1.in","r",stdin);
	freopen("c1.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>m>>f>>n;
		fr(i,1,n)
			cin>>p[i]>>s[i];
		fr(i,1,n)
			fr(j,i+1,n)
				if(p[i]>p[j]){
					swap(p[i],p[j]);
					swap(s[i],s[j]);
				}
		newn=1;
		fr(i,2,n)
			if(p[i]==p[newn])
				s[newn]=max(s[newn],s[i]);
			else
				if(s[i]>s[newn]){
					s[++newn]=s[i];
					p[newn]=p[i];
				}
		n=newn;
		ans=0;
		s[0]=-1;
		fr(i,1,m/f)
			ans=max(ans,cal(i));
		cout<<"Case #"<<ti<<": "<<ans<<endl;
	}
}