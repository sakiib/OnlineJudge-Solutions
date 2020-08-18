#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll solve(ll r,vector<ll> &V,ll s)
{
    ll sum=0,ret=0,track=0;
    for(int i=r-1;i>0;){
        //cout<<V[i]<< " ";
    }
   return ret;
}
int main()
{
    ll t,n,q,up,num,s,cnt=0,ans;
    scanf("%lld",&t);

    while(t--){
        vector<ll> V;
        cnt=0;
        scanf("%lld%lld",&n,&q);

        for(int i=0;i<n;i++){
            scanf("%lld",&num);
            V.push_back(num);
        }

      sort(V.begin(),V.end());

      for(int i=0;i<q;i++){
        scanf("%lld",&s);

        up=upper_bound(V.begin(),V.end(),s)-V.begin();
       // cout<<up<<endl;
        cnt=n-up;
       // cout<<cnt<<endl;

        ans=solve(up,V,s);
        printf("%lld\n",ans+cnt);
      }
    }
    return 0;

}
