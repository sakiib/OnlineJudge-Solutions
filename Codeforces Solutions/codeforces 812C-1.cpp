#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll n,taka,ara[100005];

ll value(ll mid)
{
    vector<ll> V;
    ll sum=0;
    for(int i=1;i<=n;i++){
        V.push_back(ara[i]+i*mid);
    }
    sort(V.begin(),V.end());
    for(int i=0;i<mid;i++){
        sum+=V[i];
    }
    return sum;
}
void solve()
{
    ll low=0,high=n,mid;

    while(abs(low-high)>=3){
        mid=(low+high)/2;
        ll X=value(mid);
        if(X<taka){
            low=mid;
        }
        else high=mid;
    }
    ll res=0;
    for(ll i=low;i<=high;i++){
        ll ans=value(i);
        if(ans>taka) break;
        else res=i;
    }
    cout<<res<< " " <<value(res);
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n>>taka;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
    }
    solve();
    return 0;
}
