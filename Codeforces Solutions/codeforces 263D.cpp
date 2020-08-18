#include<bits/stdc++.h>
using namespace std;

const int N=100005;
vector<int> graph[N];
bool visited[N];
int parent[N];
bool cycle[N];
int dist[N];
int len=0;
int n,m,k;
int ans1=0,ans2=0;

void cycle_find(int start,int par) {
    visited[start]=true;
    parent[start]=par;
    //cerr<<start<<" "<<par<<endl;
    for(int i=0;i<graph[start].size();i++) {
        int next=graph[start][i];
        if(!visited[next]) {
            dist[next]=dist[start]+1;
            cycle_find(next,start);
        }
        else if(visited[next]&&next!=par) { //found
            if(abs(dist[next]-dist[start])>=k) {
                ans1=start;
                ans2=next;
                len=abs(dist[next]-dist[start]);
                return;
            }
        }
    }
}
int main(int argc,char const *argv[]) {

    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cycle_find(1,0); //source,parent
    printf("%d\n",len+1);
    printf("%d ",ans2);
    while(ans2!=ans1) {
        ans2=parent[ans2];
        printf("%d ",ans2);
    }
    return 0;
}
