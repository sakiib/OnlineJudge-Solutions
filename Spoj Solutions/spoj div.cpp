#include<bits/stdc++.h>
using namespace std;

int nod[1000010];

void NOD() {
    for(int i=1;i<=1000000;i++) {
        for(int j=i;j<=1000000;j+=i) {
            nod[j]++;
        }
    }
}
vector<bool> isprime(1000010,true);
vector<int> prime;

void sieve() {
    isprime[0]=false,isprime[1]=false;
    prime.push_back(2);
    for(int i=4;i<=1000010;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(1000010);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(int j=i*i;j<=1000010;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(int i=3;i<=1000010;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}
int main(int argc,char const *argv[]) {
    int n;
    NOD();
    sieve();
    vector<pair<int,int> > ans;
    for(int i=1;i<=1000;i++) {
        int temp=nod[i];
        for(int j=0;j<prime.size();j++) {
            if(temp%prime[j]==0) {
                int rem=temp/prime[j];
                if(isprime[rem]&&rem!=prime[j]) {
                    ans.push_back({i,temp});
                    break;
                }
            }
        }
    }
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}


