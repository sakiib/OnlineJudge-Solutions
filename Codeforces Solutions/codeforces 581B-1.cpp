#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int ara[N];
int ans[N];

int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
    }
    int mx=ara[n]; ans[n]=0;
    for(int i=n-1;i>=1;i--) {
       if(ara[i]<=mx) {
        ans[i]=mx-ara[i]+1;
       }
       else ans[i]=0;
       mx=max(mx,ara[i]);
    }
    for(int i=1;i<=n;i++) {
       printf("%d ",ans[i]);
    }
    return 0;
}
