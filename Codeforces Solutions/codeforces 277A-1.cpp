#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
int parent[100005];

void makeset(int n) {
    for(int i=1;i<=n;i++) {
        parent[i]=i;
    }
}
int Find(int x) {
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a);
    int v=Find(b);
    if(u!=v) parent[u]=v;
}
int main(int argc,char const *argv[]) {
    int n,m;
    cin>>n>>m;
    makeset(n);
    bool found=false;
    for(int i=1;i<=n;i++) {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++) {
            found=true;
            int lang;
            cin>>lang;
            graph[lang].push_back(i);
        }
    }
    for(int i=1;i<=m;i++) {
        for(int j=0;j<graph[i].size();j++) {
            Union(graph[i][j],graph[i][0]);
        }
    }
    set<int> S;
    for(int i=1;i<=n;i++) {
        int k=Find(i);
        S.insert(k);
    }
    if(found) cout<<(int)(S.size()-1)<<endl;
    else cout<<n<<endl;
    return 0;
}
