#include<bits/stdc++.h>
using namespace std;

const int N=200005;
vector<int> graph[N];
int col[N];
bool visited[N];
int ans=0;

void dfs(int start,int parent) {
    visited[start]=true;
    int now=1;
    for(int i=0;i<graph[start].size();i++) {
        int next=graph[start][i];
        while(col[start]==now||col[parent]==now) {
            now++;
        }
        //printf("%d %d %d %d\n",next,start,parent,now);
        if(!visited[next]) {
            col[next]=now;
            ans=max(ans,now);
            dfs(next,start);
            now++; //recursion sesh hole barbe then,loop e cholbe
        }
    }
}
int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    col[1]=1;
    dfs(1,0);
    printf("%d\n",ans);
    for(int i=1;i<=n;i++) {
        printf("%d ",col[i]);
    }
    return 0;
}
