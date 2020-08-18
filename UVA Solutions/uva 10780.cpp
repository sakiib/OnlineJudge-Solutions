#include<bits/stdc++.h>
using namespace std;

vector<int> isprime(10000000,true);
vector<int> prime;
map<int,int> M;

void sieve() {
    isprime[0]=false,isprime[1]=false;
    prime.push_back(2);
    for(int i=4;i<=1000100;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(1000100);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(int j=i*i;j<=1000100;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(int i=3;i<=1000100;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}
void primefact(int m,int n) {
    if(n%2==0) {
        while(n%2==0) {
            if(m==2) M[2]++;
            n/=2;
        }
    }
    for(int i=3;i<=n/2;i++) {
        if(n%i==0) {
            while(n%i==0) {
                if(i==m) M[i]++;
                n/=i;
            }
        }
    }
    if(n>1) {
        if(m==n) M[n]++;
    }
}
int main(int argc,char const *argv[]) {
    sieve();
    int t,tc;
    scanf("%d",&t);
    int n,m;
    for(tc=1;tc<=t;tc++) {
        scanf("%d%d",&m,&n);
        for(int i=2;i<=n;i++) {
            primefact(m,n);
        }
        map<int,int> ::iterator it;
        for(auto x:M) {
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    return 0;
}
