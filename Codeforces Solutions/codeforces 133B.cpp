#include<bits/stdc++.h>
using namespace std;

const int MOD=1e6+3;
#define ll long long int

ll power(ll x,ll y){
    ll ret=1;
    for(ll i=1;i<=y;i++){
        ret=(ret*x)%MOD;
    }
    return ret%MOD;
}
ll solve(string &A){
    ll val=0;
    reverse(A.begin(),A.end());
    for(ll i=0,j=0;i<A.size();i++,j++){
        val+=((A[i]-'0')*power(2,j))%MOD;
    }
    return val%MOD;
}
int main(){

    string str,A="";
    cin>>str;
    for(int i=0;i<str.size();i++){
       if(str[i]=='>') A+="1000";
       if(str[i]=='<') A+="1001";
       if(str[i]=='+') A+="1010";
       if(str[i]=='-') A+="1011";
       if(str[i]=='.') A+="1100";
       if(str[i]==',') A+="1101";
       if(str[i]=='[') A+="1110";
       if(str[i]==']') A+="1111";
    }
    ll ans;
    ans=solve(A);
    cout<<ans<<endl;
    return 0;
}
