#include <bits/stdc++.h>
#define  ll long long
using namespace std;

int main(int argc,char const *argv[]) {
    ll a,b,c;
    cin>>a>>b>>c;
    ll mx=max(a,max(b,c));
    ll ans=max(0LL,mx-a-1)+max(0LL,mx-b-1)+max(0LL,mx-c-1);
    cout<<ans<<endl;
    return 0;
}
