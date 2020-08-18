#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
vector<bool> isprime(1000,true);
void sieve() {
    isprime[0]=false,isprime[1]=false;
    prime.push_back(2);
    for(int i=4;i<=110;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(110);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(int j=i*i;j<=110;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(int i=3;i<=110;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}
int main(int argc,char const *argv[]) {
    sieve();
    int n;
    while(scanf("%d",&n)) {
        if(n==0) break;
        vector<int> ans;
        int temp=n;
        for(int i=0;i<prime.size();i++) {
            int sum=0;
            while(n) {
                sum+=(n/prime[i]);
                n/=prime[i];
            }
            if(sum!=0) ans.push_back(sum);
            n=temp;
        }
        printf("%3d! =",temp);
        for(int i=0;i<ans.size();i++) {
            printf("%3d",ans[i]);
            if((i+1)%15==0) printf("\n   ");
        }
        cout<<endl;
    }
    return 0;
}
