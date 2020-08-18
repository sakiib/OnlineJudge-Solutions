#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<ll,ll>mp;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll m,n,a,good,bad=0,sum=0,gen;
    cin>>m>>n;
    a=m;
    while(m--){
        cin>>gen;
        mp[gen]++;
    }
    good=a*(a-1)/2;
   // cout<<good<<endl;
    map<ll,ll>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        if(it->second>1){
            sum=it->second;
            bad+=(sum*(sum-1)/2);
        }
    }
   // cout<<bad<<endl;
    cout<<good-bad<<endl;
    return 0;

}
