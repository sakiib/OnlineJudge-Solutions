#include<bits/stdc++.h>
using namespace std;

vector<int> isprime(1000000,true);
vector<int>prime;

void sieve() {
    isprime[0]=false; isprime[1]=false;
    prime.push_back(2);
    for(int i=4;i<=1000000;i+=2) isprime[i]=false;
    int sq=sqrt(1000010);
    for(int i=3;i<=sq;i++) {
        if(isprime[i]) {
            for(int j=i*i;j<=1000000;j+=2*i) {
                isprime[j]=false;
            }
        }
    }
    for(int i=3;i<=1000000;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}
int main(int argc,char const *argv[]) {
    int n;
    sieve();
    while(scanf("%d",&n)!=EOF) {
        bool m=false;
        if(n==0) break;
        int temp=n;
        if(n<0) n*=(-1),m=true;
        vector<int> fact;
        for(int i=0;i<prime.size()&&prime[i]*prime[i]<=n;i++) {
            while(n%prime[i]==0) {
                fact.push_back(prime[i]);
                n/=prime[i];
            }
        }
        if(n>1) fact.push_back(n);
        if(fact.size()==0) {
            if(temp>0) cout<<temp<<" = "<<temp<<endl;
            else cout<<temp<<" = "<<-1<<endl;
            continue;
        }
        if(temp<0) {cout<<temp<<" = "<<-1<<" ";

        for(int i=0;i<fact.size()-1;i++) {
            cout<<"x "<<fact[i]<<" ";
        }
        cout<<"x "<<fact[fact.size()-1]<<endl; }
        else {
             cout<<temp<<" =";
             for(int i=0;i<fact.size()-1;i++) {
                cout<<" "<<fact[i]<<" x";
             }
             cout<<" "<<fact[fact.size()-1]<<endl;
        }
    }
    return 0;
}
