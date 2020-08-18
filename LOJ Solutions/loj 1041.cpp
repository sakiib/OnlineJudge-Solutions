#include<bits/stdc++.h>
using namespace std;

const int inf=10000000;

struct data {
    int u,v,w;
    bool operator<(const data &q)const {
        return (w<q.w);
    }
};
int n,k,parent[1000];
vector<data> V;

void makeset(int n) {
    for(int i=1;i<=n;i++) parent[i]=i;
}
int Find(int x) {
    if(parent[x]==x) return x;
    else return parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a);
    int v=Find(b);
    if(u!=v) parent[u]=v;
}
int MST() {
    sort(V.begin(),V.end());
    int cnt=0,ans=0;
    for(int i=0;i<V.size();i++) {
        int u=V[i].u; int v=V[i].v; int w=V[i].w;
        if(Find(u)!=Find(v)) {
            Union(u,v);
            cnt++;
            ans+=w;
        }
    }
    if(cnt==(k-1)) return ans;
    else return -1;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        map<string,int> M;
        M.clear();
        char u[100],v[100];
        scanf("%d",&n);
        makeset(n);
        k=0;
        for(int i=1;i<=n;i++) {

            int w;
            scanf("%s%s",u,v);
            scanf("%d",&w);
            if(M[u]==0) M[u]=++k;
            if(M[v]==0) M[v]=++k;
            V.push_back({M[u],M[v],w});
        }
        int ans=MST();
        if(ans==-1) printf("Case %d: Impossible\n",tc);
        else printf("Case %d: %d\n",tc,ans);

        V.clear();
    }
    return 0;
}
