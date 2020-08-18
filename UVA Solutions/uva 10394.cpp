#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> prime;
vector<bool> isprime(20000010,true);

void sieve() {
    isprime[0]=false;
    isprime[1]=false;
    ll sq=sqrt(20000010);
    prime.push_back(2);
    for(ll i=3;i<=sq;i++) {
        if(isprime[i]) {
            for(ll j=i*i;j<=20000010;j+=2*i) {
                isprime[j]=false;
            }
        }
    }
}
ll t[20000010];
void twin_prime() {
    ll k=1;
    for(ll i=3;i<=20000010;i+=2) {
        if(isprime[i]&&isprime[i+2]) {
            t[k++]=i;
        }
    }
}
int main(int argc,char const *argv[]) {
    sieve();
    twin_prime();
    ll n;
    while(scanf("%lld",&n)==1) {
        printf("(%lld, %lld)\n",t[n],t[n]+2);
    }
    return 0;
}
