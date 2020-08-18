#include<bits/stdc++.h>
using namespace std;

const int N=10005;
vector<int> graph[N];
bool visited[N];

void dfs(int start) {
    visited[start]=true;

    for(auto x: graph[start]) {
        if(!visited[x]) {
            dfs(x);
        }
    }
}
int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int k;
        scanf("%d",&k);
        graph[i].push_back(k);
        graph[k].push_back(i);
    }
    int ans=0;
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            ans++;
            dfs(i);
        }
    }
    printf("%d\n",ans);
    return 0;
}
