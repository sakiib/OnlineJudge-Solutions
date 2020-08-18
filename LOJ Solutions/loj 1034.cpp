#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
bool visited[100005];
stack<int> S;

void top_sort(int start) {
    visited[start]=true;
    for(int i=0;i<graph[start].size();i++) {
        int next=graph[start][i];
        if(!visited[next]) {
            top_sort(next);
        }
    }
    S.push(start);
}
void dfs(int start) {
    visited[start]=true;
    for(int i=0;i<graph[start].size();i++) {
        int next=graph[start][i];
        if(!visited[next]) {
            dfs(next);
        }
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=k;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
        }
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=n;i++) {
            if(!visited[i]) {
                top_sort(i);
            }
        }
        memset(visited,false,sizeof(visited));
        int ans=0;
        while(!S.empty()) {
            int top=S.top();
            S.pop();
            if(!visited[top]) {
                ans++;
                dfs(top);
            }
        }
        printf("Case %d: %d\n",tc,ans);
        for(int i=1;i<=100005;i++) graph[i].clear();
    }
    return 0;
}
