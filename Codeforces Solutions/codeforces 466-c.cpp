#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,ara[100010];
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        sum+=ara[i];
    }
    if(sum%3!=0||n<3) {
        cout<<0<<endl;
        return 0;
    }
}
