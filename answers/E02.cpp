#include<iostream>
#include<cmath>
using namespace std;
int i;
#define geti(x) int x;cin>>x;
#define getl(x) long long int x;in>>x;
#define FOR(i,a,b) for(i=a;i<b;i++)
int run(){
	geti(n)
	int a[24][60]={0};
	int h,m,maximum=0;
	FOR(i,0,n-1){
		cin>>h>>m;
		a[h][m]++;
		maximum=max(maximum,a[h][m]);
	}
	cout<<maximum<<endl;
	return 0;
}
int main(){
	geti(t)
	while(t--)
		run();
	return 0;
}
