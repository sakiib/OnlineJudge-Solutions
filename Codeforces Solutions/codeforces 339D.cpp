#include<bits/stdc++.h>
using namespace std;

const int mx=(1<<17)+5;
int ara[mx+5];
int tree[4*mx];

int Query(int node) {
    return tree[node];
}
void Update(int node,int b,int e,int pos,int val,int res) {
    if(pos<b||pos>e) return;
    if(b==e&&b==pos) {
        tree[node]=val;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    Update(left,b,mid,pos,val,res-1);
    Update(right,mid+1,e,pos,val,res-1);
    if(res&1) tree[node]=tree[left] | tree[right];
    else tree[node]=tree[left] ^ tree[right];
}
void Build_Segment_Tree(int node,int b,int e,int res) {
    if(b==e) {
        tree[node]=ara[b];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    Build_Segment_Tree(left,b,mid,res-1);
    Build_Segment_Tree(right,mid+1,e,res-1);
    if(res&1) tree[node]=tree[left] | tree[right];
    else tree[node]=tree[left] ^ tree[right];
}
int main(int argc,char const *argv[]) {
    int n,m;
    scanf("%d%d",&n,&m);
    int tot=(1<<n);
    for(int i=1;i<=tot;i++) {
        scanf("%d",&ara[i]);
    }
    Build_Segment_Tree(1,1,tot,n);
    for(int i=1;i<=m;i++) {
        int pos,val;
        scanf("%d%d",&pos,&val);
        Update(1,1,tot,pos,val,n);
        int ans=Query(1);
        printf("%d\n",ans);
    }
    return 0;
}
