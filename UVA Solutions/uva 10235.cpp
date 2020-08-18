#include<bits/stdc++.h>
using namespace std;

vector<bool> isprime(10000010,true);

int rev(int val) {
    int res=0;
    while(val) {
        res*=10; res+=val%10;
        val/=10;
    } return res;
}
void sieve() {
    isprime[0]=false,isprime[1]=false;
    for(int i=4;i<=10000010;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(10000010);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(int j=i*i;j<=10000010;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
}
int main(int argc,char const *argv[]) {
    sieve();
    int n;
    while(scanf("%d",&n)!=EOF) {
        if(!isprime[n]) { printf("%d is not prime.\n",n);continue;}
        int x=rev(n);
        if(isprime[x]&&isprime[n]&&n!=x) printf("%d is emirp.\n",n);
        else printf("%d is prime.\n",n);
    }
    return 0;
}
