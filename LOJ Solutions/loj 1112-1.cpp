#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int ara[100005];
int tree[4*100005];

void build(int node,int b,int e) {
    if(b==e) {
        tree[node]=ara[b];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
    return;
}
void Update(int node,int b,int e,int pos,int add) {
    if(pos>e||pos<b) return;
    if(b==e) {
        tree[node]+=add;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    Update(left,b,mid,pos,add);
    Update(right,mid+1,e,pos,add);
    tree[node]=tree[left]+tree[right];
    return;
}
int Query(int node,int b,int e,int i,int j) {
    if(i>e||j<b) return 0;
    if(i<=b&&e<=j) {
        return tree[node];
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int p1=Query(left,b,mid,i,j);
    int p2=Query(right,mid+1,e,i,j);
    return (p1+p2);
}
int main(int argc,char const *argv[]) {
    int tc,t;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
        }
        build(1,1,n);
        printf("Case %d:\n",tc);
        while(q--) {
            int k;
            scanf("%d",&k);
            if(k==1) {
                int x;
                scanf("%d",&x);
                x++;
                printf("%d\n",ara[x]);
                Update(1,1,n,x,-ara[x]);
                ara[x]=0;
            }else if(k==2) {
               int pos,add;
               scanf("%d%d",&pos,&add);
               pos++;
               ara[pos]+=add;
               Update(1,1,n,pos,add);
            }else {
                int l,r;
                scanf("%d%d",&l,&r);
                l++,r++;
                int ans=Query(1,1,n,l,r);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
