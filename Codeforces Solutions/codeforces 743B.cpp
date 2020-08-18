#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,k,ans=1;
    cin>>n>>k;
    while(k%2==0)
    {
        k=k/2;
        ans++;
    }
    cout<<ans;
    return 0;
}
