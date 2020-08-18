#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll solve(vector<pair<ll,ll> > &V,ll dif)
{
    ll l=0,r=0,sum=0,mx=0;

   // cout<<V.size()<<endl;

    while(r<V.size()){
        if(V[r].first-V[l].first<dif){
            sum+=V[r].second;
            r++;
            mx=max(sum,mx);
           // cout<<mx<<endl;
        }
        else{
            while(V[r].first-V[l].first>=dif){
                sum-=V[l].second;
                l++;
            }
            mx=max(mx,sum);
        }
    }
     return mx;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n,dif;

    cin>>n>>dif;

    vector<pair<ll,ll> > V;

    for(int i=0;i<n;i++){
        ll t,f;
        cin>>t>>f;

        V.push_back(make_pair(t,f));
    }

    sort(V.begin(),V.end());

    cout<<solve(V,dif);

    return 0;

}
