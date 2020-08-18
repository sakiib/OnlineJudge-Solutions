#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ara[2000010];
vector<ll>v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,track=0,ans;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
        if(ara[i]==0) v.push_back(i);
    }
  /*for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }*/
    for(int i=1;i<=n;i++){
        if(i==v[track+1]) track++;
        //cout<<track<<endl;
        ans=min(abs(v[track]-i),abs(v[track+1]-i));
        cout<<ans<< " ";
    }

    return 0;
}
