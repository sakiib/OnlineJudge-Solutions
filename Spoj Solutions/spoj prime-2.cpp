#include<bits/stdc++.h>
using namespace std;

#define ll long long int

bool isprime(ll x)
{
    ll n=sqrt(x);
    if(x<2) return false;
    if(x==2||x==3) return true;
    if(x%2==0) return false;
   /* for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }*/
    for(ll j=3;j<=n;j+=2){
        if(x%j==0) return false;
    }
    return true;
}
int main()
{
    ll t,a,b;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&a,&b);
        for(ll i=a;i<=b;i++){
            if(isprime(i)) printf("%lld\n",i);
        }
        if(t) printf("\n");
    }
    return 0;
}
