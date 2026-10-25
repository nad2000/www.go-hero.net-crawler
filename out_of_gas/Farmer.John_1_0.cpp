#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=1002;
const double zero=1e-10;
double ac,d,x[maxn],t[maxn],v[maxn],v0,p0,t0,out;
int i,n,ca,ti,m;
double get(double v0,double t){
	return v0*t+0.5*ac*t*t;
}
double getTime(double a,double b){
	if(b-a<zero)
		return (a+b)/2;
	double mid=(a+b)*0.5;
	if(get(v0,mid-t0)+p0<d)
		return getTime(mid,b);
	else
		return getTime(a,mid);
}
double best(double a,double b){
	if(b-a<zero)
		return (a+b)/2;
	double mid=(a+b)*0.5;
	bool ok=true;
	int i;
	fr(i,2,n)
		if(t[i]>mid&&get(0,t[i]-mid)>x[i]){
			ok=false;
			break;
		}
	if(ok)
		return best(a,mid);
	else
		return best(mid,b);
}
int main(){
	freopen("b0.in","r",stdin);
	freopen("b0.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cout<<"Case #"<<ti<<":"<<endl;
		cin>>d>>n>>m;
		fr(i,1,n)
			cin>>t[i]>>x[i];
		fr(i,1,n-1)
			v[i]=(x[i+1]-x[i])/(t[i+1]-t[i]);
		x[n]=d;
		t[n]=(d-x[n-1])/v[n-1];
		while(m--){
			cin>>ac;
			v0=0;
			p0=0;
			t0=0;
			out=getTime(0,1e10);
/*			fr(i,1,n-1)
				if(get(v0,t[i+1]-t0)+p0>x[i+1])

					if(i==n-1){
						out=getTime(t0,1e10);
		//				cout<<"out<<"<<out<<endl;
						if(v[i]*(out-t[i])+x[i]<d)
							printf("%.8lf\n",(d-x[i])/v[i]+t[i]);
						else
							printf("%.8lf\n",out);
					}
					else{
						v0=v[i];
						p0=x[i+1];
						t0=t[i+1];
					}
				
				else
					if(i==n-1)
						printf("%.8lf\n",getTime(t0,1e10));*/
			printf("%.8lf\n",best(0,1e10)+out);
		}		
	}	
}