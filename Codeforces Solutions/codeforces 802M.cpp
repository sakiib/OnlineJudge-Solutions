#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll solve(vector<ll> &V,ll k)
{
    sort(V.begin(),V.end());
    ll ans=0;
    for(int i=0;i<V.size();i++){
        if(k==0) break;
        ans+=V[i]; k--;
    }
    return ans;
}
int main()
{
    ll n,k;
    vector<ll> V;
    cin>>n>>k;
    while(n--){
        int num;
        cin>>num;
        V.push_back(num);
    }
    cout<<solve(V,k);
}

