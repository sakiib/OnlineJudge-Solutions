#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

/*vector<LL> prime;
vector<bool> isprime(10000010,true);

void sieve() {
    isprime[0]=false,isprime[1]=false;
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
}*/
int main(int argc,char const *argv[]) {
     //sieve();
    LL q;
    scanf("%lld",&q);
    while(q--) {
        LL n;
        scanf("%lld",&n);
        if(n<4) {
            printf("-1\n");
        }
        else if(n%4==0) {
            printf("%lld\n",(n/4));
        }
        else if(n%4==1) {
            if(n==1||n==5) printf("-1\n");
            else printf("%lld\n",(n/4)-1);
        }
        else if(n%4==2) {
            if(n==2) printf("-1\n");
            else printf("%lld\n",(n/4));
        }
        else if(n%4==3) {
            if(n==3||n==7||n==11) printf("-1\n");
            else printf("%lld\n",(n/4)-1);
        }
    }
    return 0;
}
