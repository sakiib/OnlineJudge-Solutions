#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int ara[N],q[N],tree[4*N];

void build(int node,int b,int e) {
    if(b>e) return;
    if(b==e) {
        tree[node]=0;
        return;
    }
    int left=2*node; int right=2*node+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
void Update(int node,int b,int e,int pos,int val) {
    if(pos<b||pos>e) return;
    if(b==e&&b==pos) {
        tree[node]+=val;
        return;
    }
    int left=2*node; int right=2*node+1;
    int mid=(b+e)/2;
    Update(left,b,mid,pos,val);
    Update(right,mid+1,e,pos,val);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int b,int e,int i,int j) {
    if(i>e||j<b) return 0;
    if(i<=b&&j>=e) return tree[node];
    int left=2*node; int right=2*node+1;
    int mid=(b+e)/2;
    int q1=query(left,b,mid,i,j);
    int q2=query(right,mid+1,e,i,j);
    return (q1+q2);
}
int main(int argc,char const *argv[]) {
    int n;
    build(1,1,N);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d",&q[i]);
    }
    for(int i=1;i<=n;i++) {
        Update(1,1,N,ara[i],1);
        printf("ans : %d\n",query(1,1,N,1,10));
    }
    return 0;
}
