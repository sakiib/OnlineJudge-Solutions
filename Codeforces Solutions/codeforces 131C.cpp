#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
LL dp[100][100];

int nCr(LL n, LL r) {
    if(n==r) return dp[n][r]=1;
    if(r==0) return dp[n][r]=1;
    if(r==1) return dp[n][r]=n;
    if(dp[n][r]!=0) return dp[n][r];
    else return dp[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
}
int main(int argc,char const *argv[]) {
    LL b,g,t;
    cin>>b>>g>>t;
    LL ans=1;
    LL sum=0;
    for(LL i=4;i<=b;i++) {
        for(LL j=1;j<=g;j++) {
            if(i+j==t) {
                ans=1;
                //cerr<<i<<" "<<j<<endl;
                ans*=nCr(b,i);
                //cerr<<"ans : "<<ans<<endl;
                ans*=nCr(g,j);
                //cerr<<"2 : ans " <<ans<<endl;
                sum+=ans;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
