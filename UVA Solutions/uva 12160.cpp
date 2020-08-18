#include<bits/stdc++.h>
using namespace std;

const int inf=100000000;
int val[100010];
int dist[100010];
int L,U,R;
bool visited[100001];

void bfs(int start,int target) {
    queue<int> Q;
    Q.push(start);
    dist[start]=0;
    visited[start]=true;
    while(!Q.empty()) {
        int f=Q.front(); Q.pop();
        for(int i=1;i<=R;i++) {
            int next=f+val[i];
            int temp;
            if(next>=10000) temp=next-10000;
            else temp=next;
            //printf("%d ",temp);
            if(!visited[temp]||(dist[temp]>dist[f]+1)) {
                visited[temp]=true;
                dist[temp]=dist[f]+1;
                if(temp==target) break;
                Q.push(temp);
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    int tc=1;
    while(scanf("%d%d%d",&L,&U,&R)) {
        if(L==0&&U==0&&R==0) break;
        for(int i=1;i<=R;i++) {
            scanf("%d",&val[i]);
        }
        for(int i=1;i<=100005;i++) {
            dist[i]=inf;
        }
        memset(visited,false,sizeof(visited));
        bfs(L,U);
        if(dist[U]==inf) printf("Case %d: Permanently Locked\n",tc++);
        else printf("Case %d: %d\n",tc++,dist[U]);
    }
    return 0;
}
