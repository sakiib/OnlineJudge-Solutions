#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
vector<bool> isprime(10000010,true);
vector<LL> prime;

void sieve() {
    isprime[0]=false,isprime[1]=false;
    prime.push_back(2);
    for(LL i=4;i<=10000010;i+=2) {
        isprime[i]=false;
    }
    LL sq=sqrt(10000010);
    for(LL i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(LL j=i*i;j<=10000010;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(LL i=3;i<=10000010;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}
int main(int argc,char const *argv[]) {
    sieve();
    LL n;
    while(scanf("%lld",&n)) {
        if(n==0) break;
        n=abs(n);
        vector<LL> fact;
        LL sq=sqrt(n);
        for(int i=0;i<prime.size()&&prime[i]<=sq;i++) {
            if(n%prime[i]==0) {
                fact.push_back(prime[i]);
                while(n%prime[i]==0) {
                    n/=prime[i];
                }
                sq=sqrt(n);
            }
        }
        if(n!=1) fact.push_back(n);
        if((int)fact.size()>1) printf("%lld\n",fact[fact.size()-1]);
        else printf("-1\n");
    }
    return 0;
}
