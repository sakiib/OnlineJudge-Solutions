#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int tree[4*N]={0};
int lazy[4*N]={0};

void Update(int node,int b,int e,int i,int j) {
    if(lazy[node]) { //if propagation needed
        tree[node]=(e-b+1)-tree[node]; //on to off & off-on
        if(b!=e) { //if not leaf node
            lazy[2*node]=!lazy[2*node]; //toggle
            lazy[2*node+1]=!lazy[2*node+1]; //toggle
        }
        lazy[node]=0; //reset lazy node
    }
    if(i>e||j<b) return; //no iverlapping
    if(i<=b&&j>=e) { //complete overlapping
        tree[node]=(e-b+1)-tree[node];
        if(b!=e) {
            lazy[2*node]=!lazy[2*node];
            lazy[2*node+1]=!lazy[2*node+1];
        }
        return;
    }
    int left=2*node; //partial overlapping
    int right=2*node+1;
    int mid=(b+e)/2;
    Update(left,b,mid,i,j);
    Update(right,mid+1,e,i,j);
    tree[node]=tree[left]+tree[right];
}
int Query(int node,int b,int e,int i,int j) {
    if(lazy[node]) {
        tree[node]=(e-b+1)-tree[node];
        if(b!=e) {
            lazy[2*node]=!lazy[2*node];
            lazy[2*node+1]=!lazy[2*node+1];
        }
        lazy[node]=0;
    }
    if(i>e||j<b) return 0;
    if(i<=b&&j>=e) return tree[node];
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int p1=Query(left,b,mid,i,j);
    int p2=Query(right,mid+1,e,i,j);
    return (p1+p2);
}
int main(int argc,char const *argv[]) {
    int n,q;
    scanf("%d%d",&n,&q);
    while(q--) {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        switch(op) {
            case 0: Update(1,1,n,l,r);
                    break;
            case 1: printf("%d\n",Query(1,1,n,l,r));
                    break;
        }
    }
    return 0;
}
