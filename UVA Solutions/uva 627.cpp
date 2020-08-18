#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
vector<bool> isprime(100010,true);

void sieve() {
    isprime[0]=false,isprime[1]=false;
    prime.push_back(2);
    for(int i=4;i<=100010;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(100010);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(int j=i*i;j<=100010;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(int i=3;i<=100010;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}
int main(int argc,char const *argv[]) {
    int n;
    sieve();
    while(scanf("%d",&n)!=EOF) {
        if(n==0) break;
        int cnt=0;
        for(int i=0;i<prime.size();i++) {
            int left=n-prime[i];
            if(left<0) break;
            if(isprime[left]&&left>=prime[i]) {
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
