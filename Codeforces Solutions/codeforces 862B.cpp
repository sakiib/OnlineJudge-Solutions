#include<bits/stdc++.h>
using namespace std;
#define ll long long

int red=1,black=0;
vector<int> graph[100010];
bool visited[100010];
ll b=0,r=0;

void dfs(int start,int color) {
    if(color==black) color=red,r++;
    else color=black,b++;
    visited[start]=true;
    for(int i=0;i<graph[start].size();i++) {
        int now=graph[start][i];
        if(!visited[now]) {
            dfs(now,color);
        }
    }
}
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    for(int i=1;i<n;i++) {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,black);
    //cout<<b<<" "<<r<<endl;
    cout<<(b*r)-n+1<<endl;
    return 0;
}
