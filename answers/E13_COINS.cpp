#include<iostream>
#include<map>
using namespace std;
class solution{
	private:
		map <int,long long int> m;
	public:
	long long int byteland_doller_conversion(int n){
		if(n==0)return 0;
		if (m[n]!=0)return m[n];
		long long int answer=byteland_doller_conversion(n/2)+byteland_doller_conversion(n/3)+byteland_doller_conversion(n/4);
		if(answer<n)answer=n;
		m[n]=answer;
		return answer;
	}
};
int main(){
	solution s;
	long long int n;
	while(cin>>n){
		cout<<s.byteland_doller_conversion(n)<<endl;
	}
	return 0;
}
