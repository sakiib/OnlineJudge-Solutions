#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    ll a,b;
    cin>>a>>b;
    int ans=0;
    if(b%a!=0) {
        cout<<"NO"<<endl;
        return 0;
    }
    while(b%a==0&&b>a) {
        b/=a;
        ans++;
    }
    cout<<"YES"<<endl;
    cout<<ans<<endl;
    return 0;
}

