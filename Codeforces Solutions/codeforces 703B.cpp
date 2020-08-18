#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll ara[1000001];
set< pair<ll,ll> >setpair;
vector< pair<ll,ll> >vecpair;
vector< pair<ll,ll> >vecpair1;

int main()
{
    ios::sync_with_stdio(false);

    ll n,k,num,sum=0,ans,cap,fix,a,b;
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>ara[i];
    }

    for(int i=1;i<n;i++){
        setpair.insert({i,i+1});
    }
    setpair.insert({1,n});

    while(k--){
        cin>>cap;
        fix=cap;
        for(int i=1;i<cap-1;i++){
            setpair.insert({i,fix});
        }
        for(int i=n;i>cap+1;i--){
            setpair.insert({cap,i});
        }
    }
    set< pair<ll,ll> >::iterator it;
    for(it=setpair.begin();it!=setpair.end();it++){
        a=it->first;
        b=it->second;
        sum+=(ara[a]*ara[b]);
    }

    cout<<sum<<endl;

    return 0;

}
