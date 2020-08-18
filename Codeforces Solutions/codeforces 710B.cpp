#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ara[30000010];
int main()
{
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    sort(ara,ara+n);
    if(n%2==0) cout<<ara[n/2-1];
    else cout<<ara[n/2];
    return 0;

}
