#include<bits/stdc++.h>
using namespace std;

vector<bool> isprime(100000,true);
vector<int> prime;

void sieve() {
    isprime[0]=false,isprime[1]=false;
    for(int i=4;i<=10010;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(10010);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(int j=i*i;j<=10010;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
}
int fact(int x) {
    int cnt=0;
    int sq=sqrt(x);
    for(int i=1;i<=sq;i++) {
        if(x%i==0) {
            if(x/i!=i) cnt+=2;
            else cnt++;
        }
    }
    return cnt;
}
int main(int argc,char const *argv[]) {
    int t;
    sieve();
    scanf("%d",&t);
    while(t--) {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l>r) swap(l,r);
        vector<int> ans;
        for(int i=l;i<=r;i++) {
            if(isprime[fact(i)]) ans.push_back(i);
        }
        if((int)(ans.size()==0)) printf("-1\n");
        else {
            for(int i=0;i<ans.size();i++) {
                if(i==0) printf("%d",ans[i]);
                else printf(" %d",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
