#include<bits/stdc++.h>
using namespace std;
typedef int ll;
class tree{
    public:
        ll maxFrequency;
        ll leftFrequency;
        ll rightFrequency;
        ll rightElement;
        ll leftElement;
};
tree *segTree;
int a[100004],n;
tree zero;
tree join(tree left,tree right){
    tree sol;
    sol.maxFrequency=max(left.maxFrequency,right.maxFrequency);
    if(left.rightElement==right.leftElement)
    sol.maxFrequency=max(sol.maxFrequency,left.rightFrequency+right.leftFrequency);
    sol.leftFrequency=left.leftElement==right.leftElement?left.leftFrequency+right.leftFrequency:left.leftFrequency;
    sol.rightFrequency=left.rightElement==right.rightElement?left.rightFrequency+right.rightFrequency:right.rightFrequency;
    sol.leftElement=left.leftElement;
    sol.rightElement=right.rightElement;
    return sol;
}
void buildSegTree(int i,int l,int r){
    if(l>r)return ;
    if(l==r){
        segTree[i].rightElement=a[l];
        segTree[i].leftElement=a[l];
        segTree[i].maxFrequency=1;
        segTree[i].leftFrequency=segTree[i].rightFrequency=1;
    }
    else{
        int mid=(l+r)/2;
        buildSegTree(2*i,l,mid);
        buildSegTree(2*i+1,mid+1,r);
        segTree[i]=join(segTree[2*i],segTree[2*i+1]);
    }
}
tree query_old(int treeIndex,int treeLeft,int treeRight,int l,int r){
    if(treeLeft>treeRight)return zero;
    if(treeLeft==treeRight)return segTree[treeIndex];
    int treeMid=(treeLeft+treeRight)/2;
    if(treeMid<l)return query_old(2*treeIndex+1,treeMid+1,treeRight,l,r);
    if(treeMid>=r)return query_old(2*treeIndex,treeLeft,treeMid,l,r);
    return join(query_old(2*treeIndex,treeLeft,treeMid,l,r),query_old(2*treeIndex+1,treeMid+1,treeRight,l,r));
}

tree query_new(int node,int start,int end,int l,int r)
{
    if(r<start || l>end)
    {
        tree zero;
        zero.rightElement=0;
        zero.leftElement=0;
        zero.maxFrequency=0;
        zero.leftFrequency=zero.rightFrequency=0;
        return zero;
    }
    if(start>=l && end<=r)
    {
        return segTree[node];
    }
    int mid=(start+end)/2;
    tree p1=query_new(2*node,start,mid,l,r);
    tree p2=query_new(2*node+1,mid+1,end,l,r);
    tree temp=join(p1,p2);
    return temp;
}
int main(){
    
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>n;
    while(n){
        tree myTree[4*n];
        segTree=myTree;
        cin>>q;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        buildSegTree(1,0,n-1);
        int l,r;
        while(q--){
            cin>>l>>r;
            cout<<query_new(1,0,n-1,l-1,r-1).maxFrequency<<endl;
        }
        cin>>n;
    }
    return 0;
}