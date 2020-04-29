#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll tree[400005];
void build_tree(ll a[],ll node,ll start,ll end)
{
	if(start==end)
	tree[node]=a[start];
	else
	{
		ll mid=(start+end)/2;
		build_tree(a,2*node,start,mid);
		build_tree(a,2*node+1,mid+1,end);
		tree[node]=max(max(tree[2*node],tree[2*node+1]),tree[2*node]+tree[2*node+1]);
    //    cout<<tree[node];
	}
}
ll maxsum(ll node,ll start,ll end,ll x,ll y)
{
    ll p1,p2,mid;
    if(y<start || x>end)
    return -15009;
    else if(x<=start && y>=end)
    return tree[node];
    else{
        mid=(start+end)/2;
        p1=maxsum(2*node,start,mid,x,y);
        p2=maxsum(2*node+1,mid+1,end,x,y);
        return max(max(p1,p2),p1+p2);
    }
    
}
int main()
{
ll n,m,x,y,i;
cin>>n;
ll a[n+1];
for(i=1;i<=n;i++)
cin>>a[i];
build_tree(a,1,1,n);
cin>>m;
while(m--)
{
cin>>x>>y;
cout<<maxsum(1,1,n,x,y)<<endl;
}
}