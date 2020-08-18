#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc,char const *argv[]) {
    ll n;
    cin>>n;
    ll ara[10001];
    vector<ll> V;
    ll sum=0;
    for(int i=0;i<n;i++) {
        cin>>ara[i];
        if(i!=0) V.push_back((ara[i]-1)*i);
        sum+=ara[i];
    }
    for(int i=0;i<V.size();i++) {
        sum+=V[i];
    }
    cout<<sum<<endl;
    return 0;
}
