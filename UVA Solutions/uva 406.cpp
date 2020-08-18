#include<bits/stdc++.h>
using namespace std;

vector<bool> isprime(1010,true);
vector<int> prime;

void sieve() {
    isprime[0]=false,isprime[1]=false;
    prime.push_back(1);
    prime.push_back(2);
    for(int i=4;i<=1010;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(1010);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(int j=i*i;j<=1010;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(int i=3;i<=1010;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}
int main(int argc,char const *argv[]) {
    sieve();
    int n,c;
    while(scanf("%d%d",&n,&c)!=EOF) {
        int x;
        x=upper_bound(prime.begin(),prime.end(),n)-prime.begin();
        int tot;
        if(x%2==0) {
            tot=2*c;
            if(tot>=x) tot=x;
            int bad=x-tot;
            bad/=2;
            printf("%d %d: ",n,c);
            for(int i=bad;i<=tot+bad-1;i++) {
                if(i==bad) printf("%d",prime[i]);
                else printf(" %d",prime[i]);
            }
        }
        else {
            tot=2*c-1;
            if(tot>=x) tot=x;
            int bad=x-tot;
            bad/=2;
            printf("%d %d: ",n,c);
            for(int i=bad;i<=tot+bad-1;i++) {
                if(i==bad) printf("%d",prime[i]);
                else printf(" %d",prime[i]);
            }
        }
        printf("\n\n");
    }
    return 0;
}
