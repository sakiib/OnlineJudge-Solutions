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
LL NOD(LL n) {
    LL sq=sqrt(n);
    LL ret=1LL;
    for(int i=0;i<prime.size()&&prime[i]<=sq;i++) {
        if(n%prime[i]==0) {
            LL p=0;
            while(n%prime[i]==0) {
                n/=prime[i];
                p++;
            }
            sq=sqrt(n);
            p++;
            ret*=p;
        }
    }
    if(n!=1) ret*=2;
    return ret;
}
int main(int argc,char const *argv[]) {
    int t;
    sieve();
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        LL a,b;
        scanf("%lld%lld",&a,&b);
        LL ans=0,times=0;
        for(LL i=a;i<=b;i++) {
            LL temp=i;
            LL res=NOD(i);
            if(res>times) {
                times=res;
                ans=temp;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a,b,ans,times);
    }
    return 0;
}
