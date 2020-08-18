#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll ara[1000001];
set< pair<ll,ll> >setpair;
vector< pair<ll,ll> >vecpair;
vector< pair<ll,ll> >vecpair1;
map<ll,ll>mymap;

int main()
{
    ios::sync_with_stdio(false);

    ll n,k,num,sum=0,ans,cap,fix,a,b;
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>ara[i];
    }

    for(int i=1;i<n;i++){
        //vecpair.push_back({i,i+1});
        //setpair.insert({i,i+1});
        sum+=(ara[i]*ara[i+1]);
        mymap[i]=i+1;
    }
    //vecpair.push_back({1,n});
    //setpair.insert({1,n});
    sum+=(ara[1]*ara[n]);
    mymap[1]=n;
    while(k--){
        cin>>cap;
        fix=cap;
        for(int i=1;i<cap-1;i++){
            //vecpair1.push_back({i,fix});
            if(mymap[i]!=fix)
            setpair.insert({i,fix});
        }
        for(int i=n;i>cap+1;i--){
            //vecpair1.push_back({cap,i});
            if(mymap[cap]!=i)
            setpair.insert({cap,i});
        }
    }

    /*for(int i=0;i<vecpair.size();i++){
        cout<<vecpair[i].first<< " " <<vecpair[i].second<<endl;
    }
    for(int i=0;i<vecpair1.size();i++){
        cout<<vecpair1[i].first<< " " <<vecpair1[i].second<<endl;
    }*/

    set< pair<ll,ll> >::iterator it;
    for(it=setpair.begin();it!=setpair.end();it++){
        //cout<<it->first << " " <<it->second<<endl;
        a=it->first;
        b=it->second;
        sum+=(ara[a]*ara[b]);
    }

    cout<<sum<<endl;
    return 0;

}

