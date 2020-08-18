#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int solve(vector<pair<ll,ll> > &V,ll n,ll dif)
{
    sort(V.begin(),V.end());

    ll sum=0,mx=0,st=0;

    //pair<int,int> A;

    for(int i=0;i<V.size();i++){
       // A=V[i];
       // cout<<A.first<< " "<<A.second<<endl;
       cout<<V[i].first<< " " <<V[i].second<<endl;
    }

    for(int i=0;i<V.size();i++){

    }

    return mx;

}
int main()
{
    ll n,d,ans;

    vector<pair<ll,ll> > V;
    pair<ll,ll> P;

    cin>>n>>d;

    for(int i=0;i<n;i++){
        cin>>P.first>>P.second;
        V.push_back(P);
    }

    ans=solve(V,n,d);

    cout<<ans;

    return 0;
}

