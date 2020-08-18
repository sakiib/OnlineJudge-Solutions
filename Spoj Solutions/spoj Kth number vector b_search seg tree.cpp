#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
#define all(V) V.begin(),V.end()

int a[100005];
vector<LL> tree[4*100005];
LL tot;

void build(LL node,LL b,LL e) {
    if(b>e) return;
    if(b==e) {
        tree[node].push_back(a[b]);
        return;
    }
    LL left=2*node; LL right=2*node+1;
    LL mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    merge(all(tree[left]),all(tree[right]),back_inserter(tree[node]));
}
void query(LL node,LL b,LL e,LL i,LL j,LL k) {
    if(i>e||j<b) return;
    if(i<=b&&j>=e) {
        tot+=upper_bound(all(tree[node]),k)-tree[node].begin();
        return;
    }
    LL left=2*node; LL right=2*node+1;
    LL mid=(b+e)/2;
    query(left,b,mid,i,j,k);
    query(right,mid+1,e,i,j,k);
}
int main(int argc,char const *argv[]){
    LL n,q;
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    build(1,1,n);
    /*for(int i=1;i<=13;i++) {
        for(int j=0;j<tree[i].size();j++) {
            cout<<tree[i][j]<<" ";
        }
        cout<<endl;
    }*/
    LL l,r,k;
    for(int i=1;i<=q;i++) {
        tot=0;
        scanf("%lld%lld%lld",&l,&r,&k);
        LL lo=-1000000002,hi=1000000002;
        LL ans=0;
        while(lo<=hi) {
        tot=0;
        LL mid=(lo+hi)/2;
        query(1,1,n,l,r,mid);
        if(tot>=k) hi=mid-1,ans=mid;
        else lo=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
