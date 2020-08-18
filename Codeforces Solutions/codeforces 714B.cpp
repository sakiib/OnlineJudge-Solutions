#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ara[100001],sum=0;
set<ll>myset;
vector<ll>myvec;
int main()
{
    ll n,avg,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
        myset.insert(ara[i]);
    }
    if(myset.size()==1){
        cout<<"YES"<<endl;
        return 0;
    }
    if(myset.size()>=4){
        cout<<"NO"<<endl;
        return 0;
    }
    if(myset.size()==2){
        cout<<"YES"<<endl;
        return 0;
    }
    for(set<ll>::iterator it=myset.begin();it!=myset.end();it++){
        ll ans=*it;
        //cout<<ans<<endl;
        myvec.push_back(ans);
    }
   /*for(int i=0;i<myvec.size();i++){
        cout<<myvec[i]<< " ";
    }*/
    if(2*myvec[1]==myvec[0]+myvec[2]){
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;

}
