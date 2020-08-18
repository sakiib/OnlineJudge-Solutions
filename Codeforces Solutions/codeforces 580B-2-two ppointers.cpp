#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll solve(vector<pair<ll,ll> > &V,ll dif)
{
    ll l=0,r=0,sum=0,mx=0;

    for(int i=0;i<V.size();i++){
        if(V[i].first-V[r].first<dif){
            sum+=V[i].second;
           // mx=max(mx,sum);
        }
        else{
            while(V[i].first-V[r].first>=dif){
                sum-=V[r].second;
                r++;
            }
            sum+=V[i].second;
            //mx=max(mx,sum);
        }
        mx=max(mx,sum);
    }
    return mx;
}
int main()
{
    ll n,dif,ans;
    cin>>n>>dif;

    vector<pair<ll,ll> > V;

    for(int i=0;i<n;i++){
        ll t,f;
        cin>>t>>f;
        V.push_back(make_pair(t,f));
    }

    sort(V.begin(),V.end());

    ans=solve(V,dif);
    cout<<ans<<endl;
    return 0;
}
