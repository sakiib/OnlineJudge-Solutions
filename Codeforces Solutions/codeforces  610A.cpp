#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,ans;
    cin>>n;
    if(n%2==1){
        cout<<0<<endl;
        return 0;
    }
    ans=n/2;
    if(n%4==0) ans--;
    cout<<ans<<endl;
    return 0;
}
