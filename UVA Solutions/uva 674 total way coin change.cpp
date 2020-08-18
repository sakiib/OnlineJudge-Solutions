#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll ara[]={1,2,3};
ll ans[1000001]={0};

void solve()
{
    ans[0]=1;

    for(ll i=0;i<3;i++){
         for(ll j=ara[i];j<=5;j++){
            ans[j]=min(ans[j],ans[j-ara[i]]);
            cout<<j-ara[i]<< " ";
        }
        cout<<endl;
    }
   /* for(int i=0;i<100;i++){
        cout<<ans[i]<< " ";
    }*/
}
int main()
{
    ll n;
    memset(ans,0,sizeof(ans));
    solve();

    while(scanf("%lld",&n)==1){
        cout<<ans[5]<<endl;
    }
    return 0;
}
