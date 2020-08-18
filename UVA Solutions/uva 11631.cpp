#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct data {
    LL u,v,w;
    bool operator<(const data &q)const {
        return (w<q.w);
    }
};
vector<data> V;
LL ms=0;
LL parent[200005];
void makeset(LL n) {
    for(LL i=0;i<n;i++) {
        parent[i]=i;
    }
}
LL Find(LL x) {
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}
void Union(LL a,LL b) {
    LL u=Find(a);
    LL v=Find(b);
    if(u!=v) parent[u]=v;
}
void MST() {
    sort(V.begin(),V.end());
    for(int i=0;i<V.size();i++) {
        LL u=V[i].u; LL v=V[i].v; LL w=V[i].w;
        if(Find(u)!=Find(v)) {
            Union(u,v);
            ms+=w;
        }
    }
}
int main(int argc,char const *argv[]) {
    LL n,e;
    while(scanf("%lld%lld",&n,&e)) {
        if(n==0&&e==0) break;
        makeset(n);
        LL tot=0;
        ms=0;
        for(int i=1;i<=e;i++) {
            LL u,v,w;
            scanf("%lld%lld%lld",&u,&v,&w);
            V.push_back({u,v,w});
            tot+=w;
        }
        MST();
        printf("%lld\n",tot-ms);
        V.clear();
    }
    return 0;
}
