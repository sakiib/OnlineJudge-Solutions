#include<bits/stdc++.h>
using namespace std;

int ara[10005];
int tree[4*100005];
int lazy[4*100005];

vector<bool> isprime(1000100,true);

void sieve() {
    isprime[0]=false,isprime[1]=false;
    for(int i=4;i<=1000005;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(1000005);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(int j=i*i;j<=1000005;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
}
void build(int node,int b,int e) {
    if(b==e) {
        if(isprime[ara[b]]) tree[node]=1;
        else tree[node]=0;
        lazy[node]=0;
        return;
    }
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
    lazy[node]=0;
}
void update(int node,int b,int e,int i,int j,int val) {
    if(lazy[node]!=0) {
        if(isprime[lazy[node]]) tree[node]=(e-b+1);
        else tree[node]=0;
        if(b!=e) {
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
    if(i>e||j<b) return;
    if(i<=b&&j>=e) {
        if(isprime[val]) tree[node]=(e-b+1);
        else tree[node]=0;
        if(b!=e) {
            lazy[2*node]=val;
            lazy[2*node+1]=val;
        }
        return;
    }
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int b,int e,int i,int j) {
    if(lazy[node]!=0) {
        if(isprime[lazy[node]]) tree[node]=(e-b+1);
        else tree[node]=0;
        if(b!=e) {
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
    if(i>e||j<b) return 0;
    if(i<=b&&j>=e) return tree[node];
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return (p1+p2);
}
int main(int argc,char const *argv[]) {
    int n,q,tc=1,t; sieve();
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
    }
    build(1,1,n);
    printf("Case %d:\n",tc);
    for(int i=1;i<=q;i++) {
        int op;
        scanf("%d",&op);
        int l,r,val,ans;
        switch(op) {
            case 1: scanf("%d%d",&l,&r);
            ans=query(1,1,n,l,r);
            printf("%d\n",ans);
            break;
            case 0: scanf("%d%d%d",&l,&r,&val);
            update(1,1,n,l,r,val);
            break;
        }
      }
    }
    return 0;
}
