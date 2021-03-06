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
int main(int argc,char const *argv[]) {
    sieve();
    int n;
    while(scanf("%d",&n)&&n!=0) {
        bool found=false;
        int x,y;
        for(int i=0;i<prime.size();i++) {
            if(prime[i]>=n) break;
            else {
                int a=n-prime[i];
                if(isprime[a]) {found=true; x=prime[i],y=a; break;}
            }
        }
        if(found) {printf("%d:\n",n); printf("%d+%d\n",x,y);}
        else {printf("%d:\n",n);printf("NO WAY!\n");}
    }
    return 0;
}
