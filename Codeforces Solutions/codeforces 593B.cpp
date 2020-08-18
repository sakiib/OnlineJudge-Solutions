#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    ll s,t;
    map<ll,ll> M;
    for(int i=1;i<=n;i++) {
        cin>>s>>t;
        M[s]++;
        M[t]++;
        if(M[s]>=3||M[t]>=3) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
