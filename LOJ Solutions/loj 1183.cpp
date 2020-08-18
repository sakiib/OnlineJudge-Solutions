#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int tree[4*N],lazy[4*N];

int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a % b);
}
void build(int node,int b,int e) {
    if(b==e) {
        tree[node]=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
void Update(int node,int b,int e,int i,int j,int val) {
    if(lazy[node]!=-1) {
        tree[node]=lazy[node]*(e-b+1);
        if(b!=e) {
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=-1;
    }
    if(i>e||j<b) return;
    if(i<=b&&e<=j) {
        tree[node]=val*(e-b+1);
        if(b!=e) {
            lazy[2*node]=val;
            lazy[2*node+1]=val;
        }
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    Update(left,b,mid,i,j,val);
    Update(right,mid+1,e,i,j,val);
    tree[node]=tree[left]+tree[right];
}
int Query(int node,int b,int e,int i,int j) {
    if(lazy[node]!=-1) {
        tree[node]=lazy[node]*(e-b+1);
        if(b!=e) {
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=-1;
    }
    if(i>e||j<b) return 0;
    if(i<=b&&e<=j) return tree[node];
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int p1=Query(left,b,mid,i,j);
    int p2=Query(right,mid+1,e,i,j);
    return (p1+p2);
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        memset(tree,0,sizeof(tree));
        memset(lazy,-1,sizeof(lazy));
        int n,q;
        scanf("%d%d",&n,&q);
        build(1,1,n);
        printf("Case %d:\n",tc);
        while(q--) {
            int op;
            scanf("%d",&op);
            if(op==1) {
                int l,r,val;
                scanf("%d%d%d",&l,&r,&val);
                l++,r++;
                Update(1,1,n,l,r,val);
            }
            if(op==2) {
                int l,r;
                scanf("%d%d",&l,&r);
                l++,r++;
                int ans=Query(1,1,n,l,r);
                int tot=(r-l+1);
                int g=gcd(ans,tot);
                tot/=g; ans/=g;
                if(ans%tot==0) {
                    printf("%d\n",(ans/tot));
                }
                else {
                    printf("%d/%d\n",ans,tot);
                }
            }
        }
    }
    return 0;
}
