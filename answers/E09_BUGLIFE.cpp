#include<bits/stdc++.h>
using namespace std;
#define geti(x) int x;cin>>x;
#define getl(x) long long int x;in>>x;
#define FOR(i,a,b) for(i=a;i<b;i++)
#define pb push_back
bool dfs(vector <int> *v,int *color,int i){
    for(int k:v[i]){
        if(color[k]==0){
            color[k]=-color[i];
            if(dfs(v,color,k))return true;
        }
        if(color[k]==color[i]){
            return true;
        }
    }
    return false;
}
bool run(){
	int i,t1,t2,n,q;
    cin>>n>>q;
    vector <int> v[n+1];
    while(q--){
        cin>>t1>>t2;
        v[t1].pb(t2);
        v[t2].pb(t1);
    }
    int color[n+1]={0};
    for(i=1;i<=n;i++){
        if(color[i]==0&&v[i].size()!=0){
            color[i]=1;
            if(dfs(v,color,i))return true;
        }
    }
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	geti(t)
    int i;
	FOR(i,1,t+1){
        cout<<"Scenario #"<<i<<":\n";
        if(run())
            cout<<"Suspicious bugs found!\n";
		else
            cout<<"No suspicious bugs found!\n";
        
    }
	return 0;
}
