#include<bits/stdc++.h>
using namespace std;

const int N=100005;

struct segment {
    int zero=0,one=0,two=0;
    segment(){};
    segment(int _z,int _o,int _t) {
        zero=_z, one=_o, two=_t;
    }
}tree[N*4];

int lazy[4*N];


void build(int node,int b,int e) {
    if(b==e) {
        tree[node].zero=1;
        tree[node].one=0;
        tree[node].two=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node].zero=tree[left].zero+tree[right].zero;
    tree[node].one=tree[left].one+tree[right].one;
    tree[node].two=tree[node].two+tree[node].two;
}
void Update(int node,int b,int e,int i,int j) {
    if(lazy[node]!=0) {
        int k=lazy[node];
        k%=3;
        if(k==1) {
            int temp=tree[node].zero;
            tree[node].zero=tree[node].two;
            tree[node].two=tree[node].one;
            tree[node].one=temp;
        }
        if(k==2) {
            int temp=tree[node].zero;
            tree[node].zero=tree[node].one;
            tree[node].one=tree[node].two;
            tree[node].two=temp;
        }
        if(b!=e) {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(i>e||j<b) return;
    if(i<=b&&e<=j) {
        int temp=tree[node].zero;
        tree[node].zero=tree[node].two;
        tree[node].two=tree[node].one;
        tree[node].one=temp;
        if(b!=e) {
            lazy[2*node]++;
            lazy[2*node+1]++;
        }
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    Update(left,b,mid,i,j);
    Update(right,mid+1,e,i,j);
    tree[node].zero=tree[left].zero+tree[right].zero;
    tree[node].one=tree[left].one+tree[right].one;
    tree[node].two=tree[left].two+tree[right].two;
}
int Query(int node,int b,int e,int i,int j) {
    if(lazy[node]!=0) {
        int k=lazy[node];
        k%=3;
        if(k==1) {
            int temp=tree[node].zero;
            tree[node].zero=tree[node].two;
            tree[node].two=tree[node].one;
            tree[node].one=temp;
        }
        if(k==2) {
            int temp=tree[node].zero;
            tree[node].zero=tree[node].one;
            tree[node].one=tree[node].two;
            tree[node].two=temp;
        }
        if(b!=e) {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(i>e||j<b) return 0;
    if(i<=b&&e<=j) {
        return tree[node].zero;
    }
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
        memset(lazy,0,sizeof(lazy));
        memset(tree,0,sizeof(tree));
        int n,q;
        scanf("%d%d",&n,&q);
        build(1,1,n);
        printf("Case %d:\n",tc);
        while(q--) {
            int op;
            scanf("%d",&op);
            int l,r;
            scanf("%d%d",&l,&r);
            switch(op) {
                case 0: Update(1,1,n,l+1,r+1);
                break;
                case 1: printf("%d\n",Query(1,1,n,l+1,r+1));
                break;
            }
        }
    }
    return 0;
}
