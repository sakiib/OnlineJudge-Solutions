#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc,char const *argv[]) {
    ll n,k,num;
    cin>>n>>k;
    vector<ll> V;
    for(int i=0;i<n;i++) {
        cin>>num;
        V.push_back(num);
    }
    sort(V.begin(),V.end());
    ll tot=0;
    for(auto&x : V) {
        if(k>1) tot+=(x*(k--));
        else tot+=(x*k);
    }
    cout<<tot<<endl;
    return 0;
}
