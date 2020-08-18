#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<ll> prime;

void sieve_new(ll a,ll b)
{
    vector<ll> N;


}
void sieve()
{
    vector<bool> isprime(100010,true);

    isprime[0]=false;
    isprime[1]=false;
    for(ll i=2;i<=100001LL;i++){
        if(isprime[i]){
            prime.push_back(i);
            for(ll j=i*i;j<=100001LL;j+=i){
                isprime[j]=false;
            }
        }
    }
   /* for(ll i=0;i<prime.size();i++){
        cout<<prime[i]<< " ";
    }*/
}
int main()
{
    ll t,a,b;
    sieve();
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&a,&b);
        sieve_new(a,b);
    }
    return 0;
}

