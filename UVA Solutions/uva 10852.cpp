#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
vector<bool> isprime(1000010,true);
void sieve() {
    isprime[0]=false; isprime[1]=false;
    for(int i=4;i<=1000010;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(1000010);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
            for(int j=i*i;j<=1000010;j+=i*2) {
                isprime[j]=false;
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<=1000010;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}
int solve(int n) {
    int dif=0,m;
    for(int i=0;i<prime.size()&&prime[i]<=n;i++) {
        int p=n/prime[i];
        if(n-prime[i]*p>dif) {
            dif=n-prime[i]*p;
            m=prime[i];
        }
    }
    return m;
}
int main(int argc,char const *argv[]) {
    sieve();
    int n;
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        int ans=solve(n);
        printf("%d\n",ans);
    }
    return 0;
}
