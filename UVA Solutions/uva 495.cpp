#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fib[100010];
//Need Java BigInteger
void calc() {
    fib[0]=0,fib[1]=1,fib[2]=1;
    for(ll i=3;i<=5000;i++) {
        fib[i]=fib[i-1]+fib[i-2];
    }
}
int main(int argc,char const *argv[]) {
    ll n;
    calc();
    while(scanf("%lld",&n)!=EOF) {
        printf("The Fibonacci number for %lld is %lld\n",n,fib[n]);
    }
    return 0;
}
