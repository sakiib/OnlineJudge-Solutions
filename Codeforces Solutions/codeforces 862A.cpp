#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,mx;
    cin>>n>>mx;
    int ara[1000];
    bool vis[1000];
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        vis[ara[i]]=true;
    }
    int ans=0;
    for(int i=0;i<=100;i++) {
        if(i==mx) break;
        else if(!vis[i]) ans++;
    }
    if(vis[mx]) ans++;
    cout<<ans<<endl;
    return 0;
}
