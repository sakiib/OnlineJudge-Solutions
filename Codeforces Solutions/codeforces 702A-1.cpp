#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(false);
    ll n,ara[100001],cnt=1,maxs=1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    for(int i=1;i<n;i++){
        if(ara[i]>ara[i-1]){
            cnt++;
            maxs=max(maxs,cnt);
        }
        else cnt=1;
    }
    cout<<maxs<<endl;
    return 0;
}
