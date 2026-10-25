#include<iostream>
#include<set>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
int ca,a,b,i,j,ti,ans;
string s,t,sb;
char buf[20];
int main(){
	freopen("c2.in","r",stdin);
	freopen("c2.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>a>>b;
		ans=0;
		sb=string(itoa(b,buf,10));
		fr(i,a,b){
			s=string(itoa(i,buf,10));
			set<string> lst;
			fr(j,1,(int)s.size()-1){
				t=s.substr(j)+s.substr(0,j);
				if(t[0]!='0'&&s<t&&(t.size()<sb.size()||t<=sb)&&lst.find(t)==lst.end())
					lst.insert(t);
			}
			ans+=lst.size();
		}
		cout<<"Case #"<<ti<<": "<<ans<<endl;
	}
}