#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
class tree{
    public:
        ll sum;
        ll maxSum;
        ll maxPrefixSum;
        ll maxSuffixSum;
}segTree[200005];
int a[50004],n;
tree zero;
tree join(tree left,tree right){
    tree sol;
    sol.sum=left.sum+right.sum;
    sol.maxSum=max(left.maxSum,right.maxSum);
    if(left.maxSum>=0&&right.maxSum>=0)
    sol.maxSum=max(sol.maxSum,left.maxSuffixSum+right.maxPrefixSum);
    sol.maxPrefixSum=max(left.maxPrefixSum,left.sum+right.maxPrefixSum);
    sol.maxSuffixSum=max(right.maxSuffixSum,right.sum+left.maxSuffixSum);
    return sol;
}
void buildSegTree(int i,int l,int r){
    if(l>r)return ;
    if(l==r){
        segTree[i].sum=a[l];
        segTree[i].maxSum=a[l];
        segTree[i].maxPrefixSum=a[l];
        segTree[i].maxSuffixSum=a[l];
    }
    else{
        int mid=(l+r)/2;
        buildSegTree(2*i,l,mid);
        buildSegTree(2*i+1,mid+1,r);
        segTree[i]=join(segTree[2*i],segTree[2*i+1]);
    }
}

tree query(int node,int start,int end,int l,int r)
{
    if(r<start || l>end)
    {
        tree zero;
          zero.sum=-20000;
zero.maxSum=-20000;
zero.maxPrefixSum=-20000;
zero.maxSuffixSum=-20000;
    return zero;
    }
    if(start>=l && end<=r)
    {
        return segTree[node];
    }
    int mid=(start+end)/2;
    tree p1=query(2*node,start,mid,l,r);
    tree p2=query(2*node+1,mid+1,end,l,r);
    tree temp=join(p1,p2);
    return temp;
}
void update(int node,int start,int end,int leaf,int value){
    if(start==end){
        segTree[node].sum=segTree[node].maxSum=segTree[node].maxPrefixSum=segTree[node].maxSuffixSum=value;
        return;
    }
    int mid=(start+end)/2;
    if(leaf<=mid){
        update(node*2,start,mid,leaf,value);
    }
    else{
        update(2*node+1,mid+1,end,leaf,value);
    }
    segTree[node]=join(segTree[2*node],segTree[2*node+1]);
}
int main(){
    
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    zero.maxPrefixSum=zero.maxSuffixSum=zero.sum=-20000;
    zero.maxSum=-20000;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    buildSegTree(1,0,n-1);
    int q;
    cin>>q;
    int l,r;
    int type;
    while(q--){
        cin>>type>>l>>r;
        if(type)
            cout<<query(1,0,n-1,l-1,r-1).maxSum<<endl;
        else
            update(1,0,n-1,l-1,r);
    }
    return 0;
}