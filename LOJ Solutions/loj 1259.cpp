#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<bool> isprime(10000010,true);
vector<ll> prime;

void sieve() {
    isprime[0]=false,isprime[1]=false;
    prime.push_back(2);
    for(ll i=4;i<=10000010;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(10000010);
    for(ll i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(ll j=i*i;j<=10000010;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(ll i=3;i<=10000010;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}
int main(int argc,char const *argv[]) {
    sieve();
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        ll n;
        scanf("%lld",&n);
        ll ans=0;
        for(int i=0;i<prime.size()&&prime[i]<=n/2;i++) {
            ll x=n-prime[i];
            ll y=n-x;
            if(isprime[x]&&isprime[y]) ans++;
        }
        printf("Case %d: %lld\n",tc,ans);
    }
    return 0;
}
