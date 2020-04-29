#include<iostream>
#include<cmath>
using namespace std;
int i;
#define geti(x) int x;cin>>x;
#define getl(x) long long int x;in>>x;
#define FOR(i,a,b) for(i=a;i<b;i++)
int n;
int run(int *a,int l,int r){
	if(l==r)
		return 1;
	if(l>r)
		return 0;
	int mid=(l+r)/2;
	int ans=max(run(a,l,mid-1),run(a,mid+1,r));
	int midans=1;
	FOR(i,mid+1,r){
		if(a[mid]==a[i])midans++;
	}
	for(i=mid-1;i>=l;i--){
		if(a[mid]==a[i])midans--;
	}
	return max(ans,midans);
}
int main(){
	cin>>n;
	int l,r,q;
	while(n){
		cin>>q;
		int a[n];
		FOR(i,0,n)cin>>a[i];
		while(q--){
			cin>>l>>r;
			cout<<run(a,l,r)<<endl;
		}
		cin>>n;
	}
	return 0;
}
