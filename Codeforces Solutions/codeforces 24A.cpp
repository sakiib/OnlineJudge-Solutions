#include<bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define PB push_back
#define MP make_pair
#define debug(x) cerr<<"val is -> "<<x<<endl

const int N=105;

int val=0;
bool visited[N];
vector<ii> graph[N];
bool flag=false;
int finish=100;
int dist[1005][1005];

void dfs(int start,int from) {
    visited[start]=true;
    finish=start;
    for(int i=0;i<graph[start].size();i++) {
        ii P=graph[start][i];
        int edge=P.first;
        int cost=P.second;
        if(!visited[edge]) {
            visited[edge]=true;
            val+=cost;
            dfs(edge,from);
        }
    }
}
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int tot=0;
    for(int i=1;i<=n;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        tot+=c;
        graph[a].PB(MP(b,0));
        graph[b].PB(MP(a,c));
        dist[a][b]=0;
        dist[b][a]=c;
    }
    int mn=1000000;
    for(int i=1;i<=n;i++) {
        memset(visited,false,sizeof(visited));
        val=0;
        flag=false;
        dfs(i,-1);
        val+=dist[finish][i];
        mn=min(val,mn);
        //debug(val);
        //cout<<"Finish : "<<finish<<endl;
        //cout<<graph[finish][0].first<<" "<<graph[finish][0].second<<endl;
        //cout<<graph[finish][1].first<<" "<<graph[finish][1].second<<endl;
    }
    cout<<mn<<endl;
    return 0;
}
