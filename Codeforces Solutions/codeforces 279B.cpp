#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll solve(vector<ll> &V,ll t)
{
   ll l=0,r=0,sum=0,mx=0,cnt=0;

   while(r<V.size()){
     if(sum+V[r]<=t){
        sum+=V[r];
        cnt++;
        r++;
        mx=max(cnt,mx);
       // cout<<mx<<endl;
     }
     else{
        sum-=V[l];
        cnt--;
        l++;
        mx=max(cnt,mx);
     }
   }
   return mx;
}
int main()
{
    ll n,t,time;

    cin>>n>>t;

    vector<ll> V;

    for(int i=0;i<n;i++){
        cin>>time;
        V.push_back(time);
    }
   // sort(V.begin(),V.end());

    cout<<solve(V,t);

    return 0;

}
