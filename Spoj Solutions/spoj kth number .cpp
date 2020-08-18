#include<bits/stdc++.h>
using namespace std;
/* use the concept of finding nth value in a range using binary search*/
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
int query(LL node,LL b,LL e,LL i,LL j,LL k) {
    if(i>e||j<b) return 0;
    if(i<=b&&j>=e) {
        return tot=upper_bound(all(tree[node]),k)-tree[node].begin();
    }
    LL left=2*node; LL right=2*node+1;
    LL mid=(b+e)/2;
    int q1=query(left,b,mid,i,j,k);
    int q2=query(right,mid+1,e,i,j,k);
    return (q1+q2);
}
int main(int argc,char const *argv[]){
    LL n,q;
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    build(1,1,n);
    /*
    for(int i=1;i<=13;i++) {
        for(int j=0;j<tree[i].size();j++) {
            cout<<tree[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    LL l,r,k;
    for(int i=1;i<=q;i++) {
        scanf("%lld%lld%lld",&l,&r,&k);
        LL lo=-1000000002,hi=1000000002; //lets say out answer is in between lo & hi
                                         // depending on the size of n given
        LL ans=-1; // queries will be valid anyways
        while(lo<=hi) {
        LL mid=(lo+hi)/2;
        tot=query(1,1,n,l,r,mid);
        if(tot>=k) hi=mid-1,ans=mid;
        else lo=mid+1;
        //printf("Tot %lld : Mid %lld Low : %lld\n",tot,mid,lo);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
