#include<bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
int mx1=0,mx2=0,start=0,node1=0,node2=0;
int dist[1000];
bool visited[1000];

void bfs(int x) {
    for(int i=1;i<=100;i++) {dist[i]=100000;}
    queue<int> Q;
    Q.push(x);
    visited[x]=true;
    dist[x]=0;
    while(!Q.empty()) {
        int f=Q.front();
        Q.pop();
        for(int i=0;i<graph[f].size();i++) {
            int now=graph[f][i];
            if(!visited[now]||(dist[now]>dist[f]+1)) {
                visited[now]=true;
                dist[now]=dist[f]+1;
                if(dist[now]>mx1) {
                    mx1=dist[now];
                    node1=now;
                }
                Q.push(now);
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=7;i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bfs(1);
        printf("Dist : %d , Node : %d \n",mx1,node1);
        //mx2=mx1;
        mx1=0;
        node2=node1;
        memset(visited,false,sizeof(visited));
        bfs(node1);

        printf("Bef node : %d , Bef dist : %d , Af node : %d , Af dist : %d \n",
               node2,mx2,node1,mx1);
    }
    return 0;
}

/*
1 2
1 3
2 4
2 5
5 6
5 7
3 8
3 9
3 10
9 11
11 12
*/
