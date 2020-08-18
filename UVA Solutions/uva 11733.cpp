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
LL n,e,a;
LL parent[100005];

void makeset(LL n) {
    for(LL i=1;i<=n;i++) {
        parent[i]=i;
    }
}
LL Find(LL x) {
    return parent[x]==x? x : parent[x]=Find(parent[x]);
}
void Union(LL a,LL b) {
    LL u=Find(a);
    LL v=Find(b);
    if(u!=v) parent[u]=v;
}
pair<LL,LL> MST(LL n) {
    sort(V.begin(),V.end());
    LL tot=0;
    for(int i=0;i<V.size();i++) {
        LL u=V[i].u; LL v=V[i].v; LL w=V[i].w;
        if(w>=a) continue; //here we can maximize number of airports
                           // without worsening the total cost.
        if(Find(u)!=Find(v)) {
            Union(u,v);
            tot+=w;
        }
    }
    LL cnt=0;
    for(LL i=1;i<=n;i++) { // kotogulo airports
        if(parent[i]==i) {
            cnt++;
        }
    }
    tot+=cnt*a;
    //pair<int,int> p={tot,cnt};
    return {tot,cnt};
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%lld%lld%lld",&n,&e,&a);
        makeset(n);
        for(int i=1;i<=e;i++) {
            LL u,v,w;
            scanf("%lld%lld%lld",&u,&v,&w);
            V.push_back({u,v,w});
        }
        pair<LL,LL> a=MST(n);
        printf("Case #%d: %lld %lld\n",tc,a.first,a.second);
        V.clear();
    }
    return 0;
}
