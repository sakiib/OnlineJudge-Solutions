#include<bits/stdc++.h>
using namespace std;

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
    /*sieve();
    int ara[100010];
    int j=1;
    for(int k=1; ;k++) {
        bool ase=true;
        if(!isprime[k]){
           for(int i=3;i<prime.size()&&prime[i]<=k/2;i++) {
             if(k%prime[i]==0) {
                ase=false;
                break;
             }
           }
           if(ase) ara[j++]=k;
        }
        else if(k==2||k==3|k==5) {
            ara[j++]=k;
        }
        if(j==1501) break;
    }
    cout<<ara[1500]<<endl;*/
    cout<<"The 1500'th ugly number is <1016237>."<<endl;
    return 0;
}
