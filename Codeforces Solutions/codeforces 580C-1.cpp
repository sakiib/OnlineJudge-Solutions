#include<bits/stdc++.h>
using namespace std;

const int N=100010;

int cat[N];
int n,m;
vector<int> graph[N];
int ans;

void dfs(int start,int cur,int parent) {
    if(cur>m) return;
    if(graph[start].size()==1&&start!=1) {
        ans++;
        return;
    }
    for(int i=0;i<graph[start].size();i++) {
        if(graph[start][i]==parent) continue;
        if(cat[graph[start][i]]==1) dfs(graph[start][i],cur+1,start);
        else dfs(graph[start][i],0,start);
    }
}
int main(int argc,char const *argv[]) {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>cat[i];
    }
    for(int i=1;i<n;i++) {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //cout<<graph[1].size()<<endl;;
    dfs(1,cat[1],-1);
    cout<<ans<<endl;
    return 0;
}
