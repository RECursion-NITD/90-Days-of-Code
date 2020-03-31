#include<iostream>
using namespace std;
#define geti(x) int x;cin>>x;
#define getl(x) long long int x;in>>x;
#define FOR(i,a,b) for(i=a;i<b;i++)
int *a;
int i;
long long int sol(int l,int r){
	long long int ans;
	if (l==r)return a[l];
	int mid=(l+r)/2;
	ans=max(sol(l,mid),sol(mid+1,r));
	long long int ans2=0,ans1=0,ans0=0;
	FOR(i,mid+1,r+1){
		ans1+=a[i];
		ans0=max(ans1,ans0);
	}
	ans1=0;
	for(i=mid-1;i>=l;i--){
		ans1+=a[i];
		ans2=max(ans1,ans2);
	}
	return max(ans,ans2+ans0+a[mid]);
}
int run(){
	geti(l)
	geti(r)
	cout<<sol(l,r)<<endl;
	return 0;
}
int main(){
	geti(n)
	a=new int[n+5];
	FOR(i,1,n+1)cin>>a[i];
	geti(t)
	while(t--)
		run();
	return 0;
}
