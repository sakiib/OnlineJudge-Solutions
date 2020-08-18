#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<bool> isprime(10000000,true);
vector<ll> prime;

void sieve() {
    isprime[0]=false,isprime[1]=false;
    prime.push_back(2);
    for(int i=4;i<=10000000;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(10000000);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(int j=i*i;j<=10000000;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(int i=3;i<=10000000;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}
ll NOD(ll n) {
    while(n>0&&(n%2==0)) {
        n>>=1;
    }
    ll sq=sqrt(n);
    ll ret=1LL;
    for(int i=0;i<prime.size()&&prime[i]<=sq;i++) {
        ll cnt=0;
        while(n%prime[i]==0) {
            n/=prime[i];
            cnt++;
        }
        ret*=(cnt+1); sq=sqrt(n);
    }
    if(n>1) ret*=2; return ret;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    sieve();
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        ll n;
        scanf("%lld",&n);
        ll ans=NOD(n)-1;
        printf("Case %d: %lld\n",tc,ans);
    }
    return 0;
}
