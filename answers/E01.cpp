#include<iostream>
//dont forget the case of a=0;
using namespace std;
long long int sol(long long int a){
	if (a==0)return 0;
	if(a%2==1)return 1;
	else return 2*sol(a/2);
}
int main(){
	long long int a;
	while(!feof(stdin)){
		cin>>a;
		cout<<sol(a)<<endl;
	}
	return 0;
}
