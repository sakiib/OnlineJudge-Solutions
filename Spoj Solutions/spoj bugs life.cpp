#include<bits/stdc++.h>
using namespace std;

//Bipartite checking
//lesson for me,cycle with even length is Bipartite

vector<int> graph[1000005];
int color[1000005];
bool gay;
int red=1,black=0;

void dfs(int start,int col) {
    color[start]=col;
    for(int i=0;i<graph[start].size();i++) {
        int next=graph[start][i];
        if(color[next]==-1) {
            dfs(next,!col);
        }
        else {
            if(color[next]==col) gay=true;
        }
    }
}
int main(int argc,char const *argv[]){
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        memset(color,-1,sizeof(color));
        for(int i=1;i<=1000004;i++) graph[i].clear();
        int n,e;
        scanf("%d%d",&n,&e);
        for(int i=1;i<=e;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        gay=false;
        for(int i=1;i<=n;i++) {
            if(color[i]==-1) {
                dfs(i,0);
                if(gay) break;
            }
        }
        printf("Scenario #%d:\n",tc);
        if(gay) printf("Suspicious bugs found!\n");
        else printf("No suspicious bugs found!\n");
    }
    return 0;
}
