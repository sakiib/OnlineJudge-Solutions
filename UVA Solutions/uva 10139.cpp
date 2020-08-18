#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<bool> isprime(10000010,true);
vector<int> prime;

void sieve() {
    isprime[0]=false,isprime[1]=false;
    ll sq=sqrt(10000010);
    prime.push_back(2);
    for(ll i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(int j=i*i;j<=10000010;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(int i=3;i<=10000010;i+=2) {
        if(isprime[i]) {prime.push_back(i);}
    }
}
ll factors(ll a,ll p) {
    ll sum=0;
    while(a) {
        sum+=a/p;
        a/=p;
    }
    return sum;
}
bool prime_factor(ll a,ll b) {
    if(b<=a) return true;
    for(int i=0;i<prime.size()&&prime[i]*prime[i]<=b;i++) {
        if(b%prime[i]==0) {
            ll res=0;
            while(b%prime[i]==0) {
                res++;
                b/=prime[i];
            }
            if(factors(a,prime[i])<res) return false;
        }
    }
    if(b>1&&a<b) return false;
    return true;
}
int main(int argc,char const *argv[]) {
    ll a,b;
    sieve();
    while(scanf("%lld%lld",&a,&b)==2) {
          if(prime_factor(a,b)) printf("%lld divides %lld!\n",b,a);
          else printf("%lld does not divide %lld!\n",b,a);
    }
    return 0;
}
