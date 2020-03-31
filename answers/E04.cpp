#include<iostream>
#include<cmath>
using namespace std;
#define geti(x) int x;cin>>x;
#define getl(x) long long int x;in>>x;
#define FOR(i,a,b) for(i=a;i<b;i++)
long long int N;
int run(){
	cin>>N;
	double sol2=(sqrt(1+8*N)-1)/2;
	long long int sol=sol2;
	if(sol+0.0!=sol2)sol+=1;
	cout<<sol<<endl;
	return 0;
}
int main(){
	geti(t)
	while(t--)
		run();
	return 0;
}
