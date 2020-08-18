#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
vector<bool> isprime(1000010,true);

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
    sieve(); int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int a,b;
        scanf("%d%d",&a,&b);
        int start=0;
        for(int i=a; ;i++) {
            if(isprime[i]) {
                start=i; break;
            }
        }
        map<int,int> M;
        int prev=start;
        for(int i=start+1;i<=b;i++) {
           if(isprime[i]) {
             M[i-prev]++;
             prev=i;
           }
        }
        int mx=0,ans=0; bool imp=false;
        for(auto x: M) {
            if(x.second>mx) {
                mx=x.second;
                ans=x.first;
            }
        } int cnt=0;
        for(auto x: M) {
            if(x.second==mx) cnt++;
            if(cnt>=2) {imp=true; break;}
        }
        if(imp||ans==0) printf("No jumping champion\n");
        else printf("The jumping champion is %d\n",ans);
    }
    return 0;
}
