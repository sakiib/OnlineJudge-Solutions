#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

const int INF=1000000;

void dijkstra(vector<pii> graph[],int dist[],int S,int T,int N) {
    for(int i=0;i<=N;i++) {
        dist[i]=INF;
    }
    dist[S]=0;
    //cerr<<"start : "<<S<<endl;
    priority_queue<pii,vector<pii>,greater<pii> > Q;
    Q.push({dist[S],S});
    while(!Q.empty()) {
        pii T=Q.top();
        int d=T.first;//distance
        int s=T.second;//sourec
        //cerr<<"in dist[s] : "<<dist[s]<<endl;
        Q.pop();
        for(int i=0;i<graph[s].size();i++) {
            pii P=graph[s][i];
            int nd=P.first;
            int ns=P.second;
            //cerr<<"nd ns : "<<nd<<" "<<ns<<endl;
            //cerr<<"dis[nd] : nd : "<<dist[nd]<<" "<<nd<<endl;
            if(dist[nd]>dist[s]+ns) {
                dist[nd]=dist[s]+ns;
                //cerr<<"in"<<endl;
                Q.push({dist[nd],nd});
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    int N,S,T,M;
    cin>>N>>S>>T>>M;
    int dist[100010];
    memset(dist,0,sizeof(dist));
    vector<pii> graph[100010];
    for(int i=1;i<=M;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    int ans=0;
    for(int i=1;i<=N;i++) {
        dijkstra(graph,dist,i,S,N);
        //cerr<<"dist : "<<dist[S]<<endl;
        if(dist[S]<=T) ans++;
        //cerr<<"dist[1] : "<<dist[1]<<endl;
        //return 0;
    }
    cout<<ans<<endl;
    return 0;
}
