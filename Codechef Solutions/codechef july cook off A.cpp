#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc,char const *argv[]) {
   ll t,n,ara[100010];
   cin>>t;
   while(t--) {
     cin>>n;
     for(int i=1;i<=n;i++) {
        cin>>ara[i];
     }
     ll ans=0,f=ara[1];
     bool found=false;
     ll temp=ara[1];
     for(int i=2;i<=n;i++) {
        found=false;
        temp=(temp|ara[i]);
        if(ara[i]==f) continue;
        else {
            ans+=f;
            f=ara[i];
            found=true;
        }
     }
     if(!found) ans+=ara[n];
     cout<<min(ans,temp)<<endl;
   }
   return 0;
}
