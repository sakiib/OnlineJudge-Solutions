#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> prime;
vector<bool> isprime(50,true);
void sieve() {
    isprime[0]=false; isprime[1]=false;
    for(int i=4;i<=50;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(50);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
            for(int j=i*i;j<=50;j+=i*2) {
                isprime[j]=false;
            }
        }
    }
}
ll ara[1000];
void calc() {
    ara[0]=1;
    for(int i=1;i<=31;i++) {
        ara[i]=ara[i-1]*2;
    }
}
int main(int argc,char const *argv[]) {
    int n;
    sieve(); calc();
    while(scanf("%d",&n)&&n!=0) {
        ll num=ara[n-1]*(ara[n]-1);
        //printf("%lld\n",num);
        if(!isprime[n]) printf("Given number is NOT prime! NO perfect number is available.\n");
        else if(n==11||n==23||n==29) {
            printf("Given number is prime. But, NO perfect number is available.\n");
        }
        else printf("Perfect: %lld!\n",num);
    }
    return 0;
}
