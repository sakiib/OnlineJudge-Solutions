#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int ara[N];
int lazy[4*N];
int tree[4*N];

void build(int node,int b,int e) {
    if(b==e) {
        tree[node]=ara[b];
        lazy[node]=0;
        return;
    }
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    build(left,b,mid); build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
    lazy[node]=lazy[left]+lazy[right];
}
void update(int node,int b,int e,int i,int j,int val) {
    if(lazy[node]!=0) {

    }
}
int query(int node,int b,int e,int i,int j) {

}
int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
    }
    build(1,1,n);
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++) {
        int op;
        scanf("%d",&op);
        int l,r,val;
        switch(op) {
            case 1: scanf("%d%d",&l,&r);
            int ans=query(1,1,n,l,r);
            printf("%d\n",ans);
            break;
            case 2: scanf("%d%d%d",&l,&r,&val);
            update(1,1,n,l,r,val);
            break;
        }
    }
    return 0;
}
