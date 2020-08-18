#include<bits/stdc++.h>
using namespace std;

#define ll long long int
map<ll,bool> M;
set<ll> S;
void sieve(){
    vector<ll> prime;
    vector<bool> isprime(10000000,true);
    isprime[0]=false;
    isprime[1]=false;
    for(ll i=2;i<=sqrt(10000000);i++){
        if(isprime[i]){
            for(ll j=i;i*j<10000000;j++){
                isprime[i*j]=false;
            }
        }
    }
    for(ll i=0;i<=10000000;i++){
        if(isprime[i]) S.insert(i*i);
    }

}
int main(){
    sieve();
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n,num,tot;
    cin>>n;
    while(n--){
        cin>>num;
        if(S.find(num)!=S.end()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
