#include<bits/stdc++.h>
using namespace std;

vector<int> V[100010];

double DFS(int node,int parent) {
    double sum=0;
    int step=0;
    for(auto &next:V[node]) {
        cerr<<"next-parent-node : "<<next<<" "<<parent<<" "<<node<<endl;
        if(next!=parent) {
            cerr<<" in"<<endl;
            sum+=DFS(next,node)+1;
            step++;
        }
    }
    if(step!=0) {
        sum/=step;
    }
    return sum;
}
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) V[i].clear();
    for(int i=1;i<n;i++) {
        int from,to;
        cin>>from>>to;
        V[from].push_back(to);
        V[to].push_back(from);
    }
    double ans=DFS(1,0);
    cout<<setprecision(10)<<fixed<<ans<<endl;
    return 0;
}
