#include<bits/stdc++.h>
using namespace std;

const int N=10005;

int ara[N],tree[4*N];

void build(int node,int b,int e) {
    if(b>e) return;
    if(b==e) {
        tree[node]=ara[b];
        return;
    }
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=max(tree[left],tree[right]);
}
int query(int node,int b,int e,int i,int j) {
    if(i>e||j<b) return -1;
    if(i<=b&&j>=e) return tree[node];
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    int q1=query(left,b,mid,i,j);
    int q2=query(right,mid+1,e,i,j);
    return max(q1,q2);
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
       int n,k;
       scanf("%d%d",&n,&k);
       for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
       }
       build(1,1,n);
       vector<int> ans;
       int lo=1,hi=k;
       while(hi<=n) {
        int mx=query(1,1,n,lo,hi);
        ans.push_back(mx);
        lo++,hi++;
       }
       for(int i=0;i<ans.size();i++) {
        if(i==0) printf("%d",ans[i]);
        else printf(" %d",ans[i]);
       }
       printf("\n");
       ans.clear();
    }
    return 0;
}
