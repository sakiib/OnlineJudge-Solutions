#include<bits/stdc++.h>
using namespace std;

vector<int> graph[105];
stack<int> S;
bool visited[105];

void top_sort(int start) {
    visited[start]=true;
    for(auto x: graph[start]) {
        if(!visited[x]) {
            top_sort(x);
        }
    }
    S.push(start);
}
int main(int argc,char const *argv[]) {
    int n,m;
    while(scanf("%d%d",&n,&m)) {
        if(n==0&&m==0) break;
        for(int i=1;i<=m;i++) {
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
        while(!S.empty()) {
            int top=S.top();
            S.pop();
            if(S.empty()) printf("%d\n",top);
            else printf("%d ",top);
        }
        for(int i=1;i<=105;i++) graph[i].clear();
    }
    return 0;
}
