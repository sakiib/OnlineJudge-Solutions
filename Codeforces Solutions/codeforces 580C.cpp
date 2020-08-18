#include<bits/stdc++.h>
using namespace std;

const int MX=100010;

int ans;
int val[MX];
int mx;
vector<int> graph[MX];

void dfs(int start,int cat,int parent) {
    if(cat>mx) return;
    if(graph[start].size()==1&&start!=1) {
        ans++;
        //cerr<<"cur node : "<<start<<endl;
        return;
    }
    for(int i=0;i<graph[start].size();i++) {
        if(graph[start][i]==parent) {continue;}
        if(val[graph[start][i]]==1) dfs(graph[start][i],cat+1,start);
        else dfs(graph[start][i],0,start);
    }
}
int main(int argc,char const *argv[]) {
    int node;
    cin>>node;
    cin>>mx;
    for(int i=1;i<=node;i++) {
        cin>>val[i];
    }
    for(int i=1;i<node;i++) {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //cerr<<graph[4].size()<<endl;
    int cur;
    ans=0;
    dfs(1,val[1],-1);
    cout<<ans<<endl;
    return 0;
}
