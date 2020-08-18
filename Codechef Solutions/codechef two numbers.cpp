#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc,char const *argv[]) {
    ll t,a,b,n;
    cin>>t;
    while(t--) {
        cin>>a>>b>>n;
        if(n&1) a*=2;
        cout<<max(a,b)/min(a,b)<<endl;
    }
    return 0;
}
