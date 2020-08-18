#include<bits/stdc++.h>
using namespace std;
vector<bool> isprime(1000100,true);
vector<int> prime;
void sieve() {
    isprime[0]=false;
    for(int i=4;i<=1000100;i+=2) {
        isprime[i]=false;
    }
    prime.push_back(2);
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
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    string str;
    while(cin>>str) {
        int sum=0;
        for(auto c: str) {
            if(c>='a'&&c<='z') sum+=(c-'a'+1);
            else sum+=(c-'A'+27);
        }
        if(isprime[sum]) cout<<"It is a prime word."<<endl;
        else cout<<"It is not a prime word."<<endl;
    }
    return 0;
}
