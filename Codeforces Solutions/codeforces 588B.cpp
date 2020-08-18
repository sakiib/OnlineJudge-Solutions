#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>v;
vector<ll>square;
bool yes=true;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll n,sq,ans=0;

    for(ll i=2;i*i<=1000000000000;i++){
        square.push_back(i*i);
    }

    cin>>n;
    sq=sqrt(n);
    for(ll i=1;i<=sq;i++){
        if(n%i==0){
            if(n/i!=i){
                v.push_back(i);
                v.push_back(n/i);
            }
            else{
                v.push_back(i);
            }
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

   /* for(int i=0;i<v.size();i++){
        cout<<v[i]<< " ";
    }*/
   /* for(int i=0;i<d.size();i++){
        cout<<d[i]<< " ";
    }*/

    for(ll i=0;i<v.size();i++){
        for(ll j=0;j<square.size();j++){
            yes=true;
            if(v[i]%square[j]==0){
                yes=false; break;
            }
            else {
                ans=v[i];
            }
        }
        //cout<<ans<<endl;
        if(yes) break;
    }
   cout<<ans<<endl;

   return 0;
}
