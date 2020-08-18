#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
vector < ll > siam;
vector<ll > myvector;
ll n,x[110],myres=0LL;
int main (){
  cin >> n;
  x[n];
for(ll i=0;i<n;i++){
   cin >> x[i];
}
for(ll a=0;a<n;a++){
for(ll b=0;b<n;b++){
for(ll c=0;c<n;c++){
   siam.pb((x[a]*x[b])+x[c]);
 }
   }
     }

for(ll f=0;f<n;f++){
  for(ll e=0;e<n;e++){
     for(ll d=0;d<n;d++){
       if(x[d]==0) continue;
       myvector.pb((x[f]+x[e])*x[d]);
       }
     }
   }
   sort(siam.begin(),siam.end());
   sort(myvector.begin(),myvector.end());
  /* for(ll i=0;i<siam.size();i++)
   cout << siam[i] << endl;
   for(ll i=0;i<myvector.size();i++)
   cout << myvector[i] << endl;*/
int upper,lower;
for(ll i=0;i<siam.size();i++){
lower=lower_bound(myvector.begin(),myvector.end(),siam[i])-myvector.begin();
upper=upper_bound(myvector.begin(),myvector.end(),siam[i])-myvector.begin();
   myres=myres+(upper-lower);
   }

   cout << myres << endl;

return 0;
}
