#include<bits/stdc++.h>
using namespace std;

const int N=100005;

typedef long long LL;
LL n,m;
LL parent[N];

struct data {
    LL u,v,w;

    bool operator<(const data &q) const {
        return w<q.w;
    }
};
vector<data> V;

void makeset(LL n) {
    for(int i=1;i<=n;i++) {
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
    if(u!=v) {
        parent[u]=v;
    }
}
LL MST() {
    makeset(n);
    sort(V.begin(),V.end());
    LL ans=0;
    for(int i=0;i<V.size();i++) {
        LL u=V[i].u;
        LL v=V[i].v;
        LL w=V[i].w;
        if(Find(u)!=Find(v)) {
            ans+=w;
            Union(u,v);
        }
    }
    return ans;
}
int main(int argc,char const *argv[]) {
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++) {
        LL u,v,c;
        scanf("%lld%lld%lld",&u,&v,&c);
        V.push_back({u,v,c});
    }
    LL ans=MST();
    printf("%lld\n",ans);
    return 0;
}
