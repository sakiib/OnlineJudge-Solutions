#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int black,red;
bool bipartite;
vector<int> graph[210];
int color[210];

void dfs(int start,int col) {
    for(int i=0;i<graph[start].size();i++) {
        if(color[graph[start][i]]==0) {
            if(color[start]==1) {
                color[graph[start][i]]=2;
                red++;
                dfs(graph[start][i],2);
            }
            else {
                black++;
                color[graph[start][i]]=1;
                dfs(graph[start][i],1);
            }
        }
        else if(color[graph[start][i]]!=0) {
            if(color[graph[start][i]]==color[start]) {
                bipartite=false;
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        black=0,red=0;
        int n;
        scanf("%d",&n);
        for(int i=0;i<=n;i++) {
            graph[i].clear();
            color[i]=0;
        }
        for(int i=1;i<=n;i++) {
            int p; scanf("%d",&p);
            while(p--) {
                int x; scanf("%d",&x);
                if(x<1||x>n) continue;
                graph[x].push_back(i);
                graph[i].push_back(x);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
            if(color[i]==0) {
                black=0,red=0;
                bipartite=true;
                color[i]=1;
                black++;
                dfs(i,1);
                if(bipartite) ans+=max(black,red);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
