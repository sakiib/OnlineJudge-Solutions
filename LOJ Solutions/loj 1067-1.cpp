#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod=1000003;

int nCr(int n,int r) {
    int res=1;
    if(r>n-r) {
        r=n-r;
    }
    for(int i=0;i<r;i++) {
        res=(res%mod*(n-i)%mod)%mod;
        res/=(i+1);
    }
    return res%mod;
}
int main(int argc,char const *argv[]){
    int n,r;
    int tc;
    int t;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
    scanf("%d%d",&n,&r);
        int ans=nCr(n,r);
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}

