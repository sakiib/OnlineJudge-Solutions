#include<bits/stdc++.h>
using namespace std;
const int inf=1000000000;
#define pii pair<int,int>
int parent[20005];

struct data {
    int u,v,w;
    bool operator<(const data &q)const {
        return (w<q.w);
    }
};

bool visited[200005];
int dist[200005];
vector<data> V;
vector<pii> graph[200005];
int n,e;

void makeset(int n) {
    for(int i=0;i<n;i++) {
        parent[i]=i;
    }
}
int Find(int x) {
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a); int v=Find(b);
    if(u!=v) parent[u]=v;
}
void mst(int n) {
    sort(V.begin(),V.end());
    int cnt=0;
    int ans = 0;
    for(int i=0;i<V.size();i++) {
        int u=V[i].u; int v=V[i].v; int w=V[i].w;
        if(Find(u)!=Find(v)) {
            cnt++;
            ans += w;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
            Union(u,v);
        }
        if(cnt==n-1) break;
    }
    cout << "ans : " << ans << endl;
}

int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        scanf("%d",&n);
        makeset(n);
        for( int i = 0; i < n; i++ ) {
            for( int j = i+1; j < n; j++ ) {
                V.push_back( {i,j,i^j} );
            }
        }
        mst(n);
        V.clear();
    }
    return 0;
}
