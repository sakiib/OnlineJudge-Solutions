#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll a,b,x,y,i;

int solve(ll x)
{



}
int main()
{

    while(scanf("%lld%lld",&a,&b)!=EOF){
        if(a>b) swap(a,b);

        ll ans=1,mx=1;
        x=a,y=b;
        for(ll i=a;i<=b;i++){
            ans=solve(i);
            mx=max(mx,ans);
        }
        printf("%lld %lld %lld\n",x,y,mx);
    }
    return 0;

}
