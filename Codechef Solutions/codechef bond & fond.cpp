#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll ara[100];
ll INF=999999999999999999LL;
ll gen_power()
{
    ara[0]=1;
    for(int i=1;i<63;i++){
        ara[i]=ara[i-1]*2;
    }
   /* for(int i=0;i<63;i++){
        cout<<ara[i]<< " ";
    }*/
}
int main()
{
    gen_power();
    ll t,n,ans;
    cin>>t;
    while(t--){
        cin>>n;
        ans=INF;
        for(int i=0;i<63;i++){
            ans=min(ans,abs(n-ara[i]));
            //cout<<abs(n-ara[i])<< " ";
            //cout<<ans<< " ";
        }
        cout<<ans<<endl;
    }
  return 0;
}
