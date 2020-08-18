#include<bits/stdc++.h>
using namespace std;

vector<int> V[10000];
bool visited[10000];

void dfs(int st) {
    visited[st]=true;
    for(auto x: V[st]) {
        if(!visited[x]) {
            dfs(x);
        }
    }
}
int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++) {
        int u,v;
        cin>>u>>v;
        visited[u]=true;
        visited[v]=true;
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        if(!visited[i]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
