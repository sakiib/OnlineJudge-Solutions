#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(vector<pair<ll,ll> > &V,ll k)
{
    ll ans=0;
    vector<ll> A,B,C;

    for(int i=0;i<V.size();i++){
        ans+=min(V[i].first,V[i].second);
        A.push_back(min(V[i].first,V[i].second));
    }
    for(int i=0;i<V.size();i++){
        B.push_back(min(2*V[i].first,V[i].second));
    }
    for(int i=0;i<A.size();i++){
        C.push_back(B[i]-A[i]);
    }
    sort(C.rbegin(),C.rend());
   /* for(int i=0;i<C.size();i++){
        cout<<C[i]<< " ";
    }*/
    for(int i=0;i<k;i++){
        ans+=C[i];
    }

   return ans;

}
int main()
{
    ll n,k,a,b,ans;
    cin>>n>>k;
    vector<pair<ll,ll> > V;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        V.push_back(make_pair(a,b));
    }
    ans=solve(V,k);
    cout<<ans<<endl;
    return 0;
}
