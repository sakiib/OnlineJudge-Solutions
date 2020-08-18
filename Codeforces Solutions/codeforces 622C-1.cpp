#include<bits/stdc++.h>
using namespace std;

int ara[200010];
int dp[200010];
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        if(ara[i]==ara[i-1]) dp[i]=dp[i-1];
        else dp[i]=i-1;
    }
    int l,r,x;
    while(m--) {
        cin>>l>>r>>x;
        if(ara[r]!=x) cout<<r<<endl;
        else {
           if(dp[r]>=l) cout<<dp[r]<<endl;
           else cout<<-1<<endl;
        }
    }
    return 0;
}
