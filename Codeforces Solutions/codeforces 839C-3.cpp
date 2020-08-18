#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100010];
bool visited[100010];

double dfs(int start) {
    visited[start]=true;
    double total=0.0;
    int step=0;
    for(auto x:graph[start]) {
        if(!visited[x]) {
            total+=(dfs(x)+1);
            step++;
        }
    }
    if(step>0) {
        total/=step;
    }
    return total;
}
int main(int argc,char const *argv[]) {
    memset(visited,false,sizeof(visited));
    int node;
    cin>>node;
    for(int i=1;i<=node-1;i++) {
        int from,to;
        cin>>from>>to;
        graph[from].push_back(to);//undirected edges a to b
        graph[to].push_back(from);// also b to a
    }
    double ans=dfs(1);//starting node has no parent
    cout<<setprecision(10)<<fixed<<ans<<endl;
    return 0;
}
