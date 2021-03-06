#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
set<LL> S;
vector<bool> isprime(10000010,true);

void sieve() {
    isprime[0]=false,isprime[1]=false;
    S.insert(2*2);
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
        if(isprime[i]) S.insert(i*i);
    }
}
int main(int argc,char const *argv[]) {
    sieve();
    LL q;
    scanf("%lld",&q);
    while(q--) {
        LL n;
        scanf("%lld",&n);
        if(S.find(n)!=S.end()) puts("YES");
        else puts("NO");
    }
    return 0;
}
