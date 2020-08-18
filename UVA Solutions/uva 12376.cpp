#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int t,tc,ans,ind,mx,cur;
    cin>>t;
    for(tc=1;tc<=t;tc++) {
        int ara[1010];
        bool vis[1010];
        memset(ara,0,sizeof(ara));
        memset(vis,false,sizeof(vis));
        ans=0,cur=0,mx=0,ind=0;
        vector<int> V[1010];
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++) {
            cin>>ara[i];
        }
        for(int i=1;i<=k;i++) {
            int from,to;
            cin>>from>>to;
            V[from].push_back(to);
        }
        for(int i=0;i<k;i++) {
            mx=0;
            bool found=false;
            for(int j=0;j<V[cur].size();j++) {
                if(ara[V[cur][j]]>mx&&!vis[V[cur][j]]) {
                    mx=ara[V[cur][j]];
                    ind=V[cur][j];
                    found=true;
                }
            }
            if(found) {
                ans+=mx;
                vis[ind]=true;
                cur=ind;
            }
        }
        printf("Case %d: %d %d\n",tc,ans,ind);
    }
    return 0;
}
