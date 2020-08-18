#include<bits/stdc++.h>
using namespace std;

const int N=1000005;
typedef long long LL;
LL ans[5*N];
vector<bool> isprime(1000010,true);
vector<LL> prime;

void sieve() {
    isprime[0]=false,isprime[1]=false;
    prime.push_back(2);
    for(LL i=4;i<=1000010;i+=2) {
        isprime[i]=false;
    }
    LL sq=sqrt(1000010);
    for(LL i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(LL j=i*i;j<=1000010;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(int i=3;i<=1000010;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}
LL sieve_phi(LL n) {
    LL idx=0; LL p=prime[idx]; LL ans=n;
    while(p*p<=n) {
        if(n%p==0) ans-=(ans/p);
        while(n%p==0) {
            n/=p;
        }
        p=prime[++idx];
    }
    if(n>1) ans-=(ans/n);
    return ans;
}
void calc() {
    ans[0]=0;
    for(LL i=1;i<=5000000;i++) {
        LL k=sieve_phi(i*1LL);
        ans[i]=k*k;
        ans[i]+=ans[i-1];
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    sieve();
    calc();
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        LL a,b;
        scanf("%lld%lld",&a,&b);
        printf("Case %d: %lld\n",tc,ans[b]-ans[a-1]);
    }
    return 0;
}
