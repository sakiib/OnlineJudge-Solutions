#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> graph[100010];
bool visited[100010];

double dfs(ll child,ll parent) {
    visited[child]=true;
    double sum=0;
    ll step=0;
    //cout<<sum<< " "<<step<<endl;
    for(int i=0;i<graph[child].size();i++) {
        if(graph[child][i]!=parent) {
            sum+=dfs(graph[child][i],child)+1;
            step++;
            //cout<<sum<< " "<<step<<endl;
        }
    }
    //cout<<"s : "<<sum<<endl;
    if(step>0) {
       sum/=step;
    }
    return sum;
}
int main(int argc,char const *argv[]) {
    ll n;
    memset(visited,false,sizeof(visited));
    cin>>n;
    for(int i=1;i<=n-1;i++) {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    double ans=dfs(1,0);
    cout<<setprecision(10)<<fixed<<ans<<endl;
    return 0;
}
