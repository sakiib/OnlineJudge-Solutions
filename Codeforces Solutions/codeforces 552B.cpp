#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll ans=0,k=0;
    ll x=n;
    while(n!=0) {
        n=n/10;
        k++;
    }
    ans+=k*(x+1)-1;
    ll m=1;
    for(int i=0;i<k-1;i++) {
         m*=10;
        ans-=(m);
    }
    cout<<ans<<endl;
    return 0;
}
