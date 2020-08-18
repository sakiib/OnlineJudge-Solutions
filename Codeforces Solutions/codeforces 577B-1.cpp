#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n,m;
ll ara[1000010];

bool solve(ll i,ll sum) {

    if(sum%m==0&&sum!=0) {
        return true;
    }
    return solve(i+1,sum)+solve(i,sum+ara[i]);
    cout<<"If it comes here,then trouble.."<<endl;
}
int main(int argc,char const *argv[]) {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    if(solve(1,0)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
