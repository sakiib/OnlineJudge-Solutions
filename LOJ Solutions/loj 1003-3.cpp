#include<bits/stdc++.h>
using namespace std;

vector<int> graph[10000];
int visited[10000];
bool cycle;
int white=0,grey=1,black=2;

void dfs(int start) {
    if(visited[start]==black) return;
    if(visited[start]==grey) {cycle=true; return;}
    visited[start]=grey;
    for(int i=0;i<graph[start].size();i++) {
        dfs(graph[start][i]);
    }
    visited[start]=black;
    return;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n;
        scanf("%d",&n);
        int cnt=1;
        map<string,int> M;
        char a[20],b[20];
        for(int i=1;i<=n;i++) {
            scanf("%s %s",a,b);
            if(M[a]==0) M[a]=cnt++;
            if(M[b]==0) M[b]=cnt++;
            graph[M[a]].push_back(M[b]);
        }
        cycle=false;
        memset(visited,white,sizeof(visited));
        for(int i=1;i<=cnt;i++) {
                dfs(i);
                if(cycle) break;
        }
        if(cycle) printf("Case %d: No\n",tc);
        else printf("Case %d: Yes\n",tc);
        for(int i=1;i<=cnt+5;i++) graph[i].clear();
    }
    return 0;
}
