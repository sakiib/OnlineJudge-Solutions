#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<bool> isprime(1000100,true);
vector<ll> prime;

void sieve() {
    isprime[0]=false,isprime[1]=false;
    prime.push_back(2);
    for(int i=4;i<=1000100;i+=2) {
        isprime[i]=false;
    }
    ll sq=sqrt(1000100);
    for(ll i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(ll j=i*i;j<=1000100;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(ll i=3;i<=1000100;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}

ll ara[5*1000100]={0};

int calc(ll x) {
    vector<ll> val;
    int temp=x;
    int vag=1;
    for(int i=0;i<prime.size();i++) {
        if(x%prime[i]==0) {
            vag*=prime[i];
            val.push_back(prime[i]);
            x/=prime[i];
            while(x%prime[i]==0) {
            x/=prime[i];
          }
        }
    }
    if(x>1) val.push_back(x),vag*=x;
    for(int i=0;i<val.size();i++) {
        temp*=(val[i]-1);
    }
    temp/=vag;
    return (temp*temp);
}
int main(int argc,char const *argv[]) {
    sieve();
    ara[1]=0;
    for(ll i=2;i<=5*1000100;i++) {
        ara[i]=calc(i);
        ara[i]+=ara[i-1];
    }
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++) {
        ll a,b;
        cin>>a>>b;
        printf("Case %d: %d\n",tc,ara[b]-ara[a-1]);
    }
    return 0;
}
