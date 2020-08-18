#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<ll,bool> M;

int main(int argc,char const *argv[]) {
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        ll val;
        cin>>val;
        M[val]=true;
    }
    vector<ll> ans;
    for(ll i=1;i<=1000000000;i++) {
        if(!M[i]) {
            if(m>=i) m-=i;
            else break;
            M[i]=true;
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto &x:ans) {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
