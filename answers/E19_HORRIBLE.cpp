#include<iostream>
using namespace std;
typedef long long ll;
class node{
public:
    long long int sum;
    long long int extra;
    node *left=NULL;
    node *right=NULL;
    node(ll sum=0,ll extra=0){
        this->sum=sum;
        this->extra=extra;
    }
    void destroy(){
        if(left!=NULL){
            left->destroy();
            free(left);
        }
        if(right!=NULL){
            right->destroy();
            free(right);
        }
    }
    ~node(){
        destroy();
    }
    void createChildren(){
        if(left==NULL)left=(node *)malloc(sizeof(node));
        if(right==NULL)right=(node *)malloc(sizeof(node));
    }
    void propagateExtra(ll start,ll end){
        if(start==end)return;
        ll mid=(start+end)/2;
        left->extra+=extra;
        left->sum+=extra*(mid-start+1);
        right->extra+=extra;
        right->sum+=extra*(end-mid-1+1);
        extra=0;
    }
    void update(ll start,ll end,ll l,ll r,ll value){
        if(l>end||r<start)
            return;
        if(l<=start&&end<=r){
            if(start!=end)
                extra+=value;
            sum+=(end-start+1)*value;
            return;
        }
        ll mid=(start+end)/2;
        createChildren();
        if(extra)propagateExtra(start,end);
        left->update(start,mid,l,r,value);
        right->update(mid+1,end,l,r,value);
        sum=right->sum+left->sum;
    }
    long long int query(ll start,ll end,ll l,ll r){
        if(l>end||r<start)return 0;
        if(l<=start&&end<=r)return sum;
        int mid=(start+end)/2;
        createChildren();
        if(extra)propagateExtra(start,end);
        return left->query(start,mid,l,r)+right->query(mid+1,end,l,r);
    }
};
void run(node &head){
    int n,c;
    cin>>n>>c;
    ll type,l,r,value;
    while(c--){
        cin>>type>>l>>r;
        if(!type){
            cin>>value;
            head.update(1,n,l,r,value);
        }
        else{
            cout<<head.query(1,n,l,r)<<"\n";
        }

    }
}
int main(){
    ll t;
    cin>>t;
    node head[t];
    while(t--){
        run(head[t]);
    }
}