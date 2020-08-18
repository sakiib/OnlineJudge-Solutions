#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fact[10];
map<ll,string> M;

void calc() {
    fact[0]=1LL; fact[1]=1LL;
    for(ll i=2;i<=9;i++) {
        fact[i]=i*fact[i-1];
    }
}
ll get_ans(ll val) {
    ll ret=1LL;
    while(val) {
        ll k=(val%10);
        ret*=fact[k];
        val/=10;
    } return ret;
}
int main(int argc,char const *argv[]) {
    calc();
    ll n;
    cin>>n;
    ll val;
    cin>>val;
    M[0]="1"; M[1]="1"; M[2]="2"; M[3]="3";
    M[4]="322"; M[5]="5"; M[6]="53"; M[7]="7";
    M[8]="7222"; M[9]="7332";
    string ans="";
    while(val>1) {
        int k=val%10;
        val/=10;
        if(k<=1) continue;
        ans+=M[k];
        //cerr<<k<<" ";
    }
    sort(ans.rbegin(),ans.rend());
    cout<<ans<<endl;
    return 0;
}
