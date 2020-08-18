#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    ll n;
    ll a=1,temp=10,ans=1;
    while(scanf("%lld",&n)==1) {
        a=1,ans=1;
        while(a%n!=0) {
            a=(a*temp+1)%n;
            ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
