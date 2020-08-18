#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[1000100];
ll dp[1000100];
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    if(n>k) {
        cout<<"YES"<<endl;
        return 0;
    }

    return 0;
}
