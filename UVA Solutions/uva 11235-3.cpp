#include<bits/stdc++.h>
using namespace std;

const int N=1000005;

int ara[N];
int cnt[N];
int start[N];
int tree[4*N];

void build(int node,int b,int e) {
    if(b==e) {
        tree[node]=cnt[ara[b]];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=max(tree[left],tree[right]);
}
int Query(int node,int b,int e,int i,int j) {
    if(i>e||j<b) return -1;
    if(i<=b&&j>=b) return tree[node];
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int p1=Query(left,b,mid,i,j);
    int p2=Query(right,mid+1,e,i,j);
    return max(p1,p2);
}
int main(int argc,char const *argv[]) {
    int n,q;
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    while(scanf("%d",&n)) {
        memset(cnt,0,sizeof(cnt));
        memset(tree,0,sizeof(tree));
        memset(start,0,sizeof(start));
        if(n==0) break;
        scanf("%d",&q);
        for(int i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
            cnt[ara[i]]++;
            if(cnt[ara[i]]==1) {
                start[ara[i]]=i;
            }
        }
        build(1,1,n);
        while(q--) {
            int l,r;
            scanf("%d%d",&l,&r);
            if(ara[l]==ara[r]) {
                printf("%d\n",(r-l+1));
                continue;
            }
            int left_occur=cnt[ara[l]]-l+start[ara[l]];
            int right_occur=r-start[ara[r]]+1;
            int ans=max(left_occur,right_occur);
            int r1=start[ara[l]]+cnt[ara[l]];
            int r2=start[ara[r]]-1;
            if(r1<=r2) {
            int val=Query(1,1,n,r1,r2);
            ans=max(ans,val);
            }
            printf("%d\n",ans);
            cerr<<"left - right - r1 - r2 : "<<left_occur<<" "<<
            right_occur<<" "<<r1<<" "<<r2<<endl;
        }
    }
    return 0;
}
