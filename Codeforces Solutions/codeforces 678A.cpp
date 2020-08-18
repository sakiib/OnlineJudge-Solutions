#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,k;
    cin>>n>>k;
    if(n<k){
        cout<<k<<endl;
        return 0;
    }
    ll ans=n%k;
    if(ans==0){
        cout<<n+k<<endl;
    }
    else cout<<n+k-ans<<endl;
    return 0;
}
