#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll p;
map<ll,ll> M;

ll power(ll a,ll b){
    ll ret=1;
    for(ll i=1;i<=b;i++){
        ret=(ret*a);
    }
    return ret;
}
void primefact(ll p){
    while(p%2==0){
        M[2]++;
        p=p/2;
    }
    for(ll i=3;i<=(p)/2;i+=2){
        while(p%i==0){
            M[i]++;
            p=p/i;
        }
    }
    if(p>1) M[p]++;
}
int main(){
    ll cnt=1;
    cin>>p;
    p--;
    primefact(p);
    map<ll,ll> :: iterator it;
    for(it=M.begin();it!=M.end();it++){
            //cout<<it->first<< " "<<it->second<<endl;
            cnt*=power(it->first,it->second-1)*(it->first-1);
            //cout<<cnt<<endl;
    }
    cout<<cnt<<endl;
    return 0;
}
