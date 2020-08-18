#include<bits/stdc++.h>
using namespace std;
const int N=100005;
typedef long long LL;
LL a[N],b[N];
LL parent[N],sum[N],ans[N];
bool visited[N];

void makeset(LL n) {
    for(LL i=1;i<=n;i++) {
        parent[i]=i;
        sum[i]=a[i];
    }
}
LL Find(LL x) {
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}
void Union(LL a,LL b) {
    LL u=Find(a); LL v=Find(b);
    if(u!=v) {
        parent[u]=v;
        sum[v]+=sum[u];
    }
}
int main(int argc,char const *argv[]) {
    LL n;
    scanf("%lld",&n);
    for(LL i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    for(LL i=1;i<=n;i++) {
        scanf("%lld",&b[i]);
    }
    makeset(n);
    LL mx=0;
    for(LL i=n;i>=1;i--) {
        LL x=b[i];
        ans[i]=mx;
        visited[x]=true;
        if(visited[x+1]) Union(x,x+1);
        if(visited[x-1]) Union(x,x-1);
        mx=max(mx,sum[Find(x)]);
        //printf("mx : %lld\n",mx);
    }
    for(LL i=1;i<=n;i++) {
        printf("%lld\n",ans[i]);
    }
    return 0;
}
