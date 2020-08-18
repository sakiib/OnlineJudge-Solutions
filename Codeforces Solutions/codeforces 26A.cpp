#include<bits/stdc++.h>
using namespace std;

bool isprime(int x) {
    int sq=sqrt(x);
    for(int i=2;i<=sq;i++) {
        if(x%i==0) return false;
    }
    return true;
}
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    if(n<6) {
        cout<<0<<endl;
        return 0;
    }
    int ans=0;
    for(int i=6;i<=n;i++) {
            int k=sqrt(i);
            int cnt=0;
        for(int j=2;j<=k;j++) {
          if(i%j==0) {
            if(isprime(j)) cnt++;
            if((i/j)!=j&&isprime(i/j)) cnt++;
          }
        }
        if(cnt==2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
