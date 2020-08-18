#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll solve(vector<ll> &P,vector<ll> &C,ll f)
{
    vector<pair<ll,ll> > K;
    vector<ll> I;
    ll sum=0;
    //sort(P.begin(),P.end());
    for(int i=0;i<P.size();i++){
        if(P[i]!=0)
        K.push_back(make_pair(C[i],2*P[i]));
    }

    sort(K.begin(),K.end());
    reverse(K.begin(),K.end());

    for(int i=0;i<K.size();i++){
       //cout<<K[i].first<< " " <<K[i].second<<endl;
       if(f>0){
         sum+=min(K[i].first,K[i].second);
         f--;
       }
       else{
        sum+=min(K[i].first,K[i].second/2);
       }
    }
   //cout<<sum;
   return sum;

}
int main()
{
    ll n,f,ans,a,b;
    cin>>n>>f;
    vector<ll> P,C;
    for(int i=0;i<n;i++){
       cin>>a>>b;
       P.push_back(a);
       C.push_back(b);
    }
    ans=solve(P,C,f);
    cout<<ans;
    return 0;
}
