#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<bool> isprime(20000005,true);
vector<ll> prime;
vector<pair<ll,ll> > P[100010];
ll A[1000100],B[1000100];

void sieve() {
    isprime[0]=false,isprime[1]=false;
    //prime.push_back(2);
    for(ll i=4;i<=20000005;i+=2) {
        isprime[i]=false;
    }
    ll sq=sqrt(20000005);
    for(ll i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(ll j=i*i;j<=20000005;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    int k=1;
    for(ll i=3;i<=20000005;i+=2) {
        if(isprime[i]&&isprime[i+2]) {
            A[k]=i,B[k]=(i+2);
            k++;
        }
    }
}
int main(int argc,char const *argv[]) {
    sieve();
    int n;
    while(scanf("%d",&n)!=EOF) {
        printf("(%lld, %lld)\n",A[n],B[n]);
    }
    return 0;
}
