#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int MX=20000;

int n,target;
bool visited[N];
int dist[N]={0};

void bfs(int start) {
    queue<int> Q;
    Q.push(start);
    visited[start]=true;
    dist[start]=0;
    while(!Q.empty()) {
        int F=Q.front();
        Q.pop();
        if(F==target) return;
        int now=F*2;
        if(!visited[now]&&now<MX) {
            visited[now]=true;
            dist[now]=dist[F]+1;
            Q.push(now);
        }
        int now1=F-1;
        if(!visited[now1]&&now1>=0) {
            visited[now1]=true;
            dist[now1]=dist[F]+1;
            Q.push(now1);
        }
    }
}
int main(int argc,char const *argv[]) {
    cin>>n>>target;
    memset(visited,false,sizeof(visited));
    bfs(n);
    cout<<dist[target]<<endl;
    return 0;
}
