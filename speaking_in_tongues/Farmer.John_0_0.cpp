#include<iostream>
#include<stdio.h>
#include<string.h>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const string sa="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
const string sb="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
char x[256];
int i,ca,ti;
string s;
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	memset(x,0,sizeof(x));
	fr(i,0,(int)sa.size()-1)
		x[sa[i]]=sb[i];
//	fr(i,'a','z')
//		cout<<char(i)<<" "<<(int)x[i]<<endl;
	x['q']='z';
	x['z']='q';
	cin>>ca;
	getline(cin,s);
	fr(ti,1,ca){
		getline(cin,s);
		cout<<"Case #"<<ti<<": ";
		fr(i,0,(int)s.size()-1)
			cout<<x[s[i]];
		cout<<endl;
	}
}