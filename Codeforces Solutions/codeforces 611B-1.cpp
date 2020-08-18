#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll a,b,ans,cnt=0;
    cin>>a>>b;
    for(int i=0;i<63;i++){
        for(int j=0;j<=i-2;j++){
            ans=(1LL<<i)-1-(1LL<<j);
           // cout<<ans<<endl;
           if(ans>=a&&ans<=b){
            //cout<<i<< " "<<j<<endl;
            cnt++;
           }
        }
    }
    cout<<cnt;
    return 0;
}
