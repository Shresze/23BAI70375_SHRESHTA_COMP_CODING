#include<bits/stdc++.h>
using namespace std;
#define int long long
int _,n,u,a[1<<20],c,d,y;
int S(int x){
	c=d=0;
	for(int i=1;i<=n;i++)
		y=(x-a[i]),c+=y%2,d+=y/2;
	y=max(0ll,(d-c+1)/3),c+=2*y,d-=y;
	return max(2*c-1,2*d);
} 
main(){
	for(cin>>_;_--&&cin>>n;){
		u=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],u=max(u,a[i]);
		cout<<min(S(u),S(u+1))<<'\n';
	}
}
