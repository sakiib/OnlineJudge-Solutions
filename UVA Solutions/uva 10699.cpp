#include<bits/stdc++.h>
using namespace std;

vector<bool> isprime(1000010,true);
vector<int> prime;

void sieve() {
    isprime[0]=false,isprime[1]=false;
    prime.push_back(2);
    for(int i=4;i<=1000010;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(1000010);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(int j=i*i;j<=1000010;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(int i=3;i<=1000010;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}
int main(int argc,char const *argv[]) {
    int n;
    sieve();
    while(scanf("%d",&n)) {
        if(n==0) break;
        int temp=n;
        int sqrtn=sqrt(n);
        int ans=0;
        for(int i=0;i<prime.size()&&prime[i]<=sqrtn;i++) {
            if(n%prime[i]==0) {
                ans++;
                while(n%prime[i]==0) {
                    n/=prime[i];
                }
                sqrtn=sqrt(n);
            }
        }
        if(n!=1) ans++;
        printf("%d : %d\n",temp,ans);
    }
    return 0;
}
