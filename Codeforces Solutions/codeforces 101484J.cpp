#include<bits/stdc++.h>
using namespace std;

#define ll long long

void check(ll a,ll b) {
    vector<ll> V;
    for(ll i=1;i<=1000;i++) {
        if(a+i>b&&b+i>a&&a+b>i) {
            V.push_back(i);
        }
    }
    for(auto &x:V) {
        cout<<x<< " ";
    }
}
int main(int argc,char const *argv[]) {
    ll a,b;
    cin>>a>>b;
    if(a<b) swap(a,b);
    //check(a,b);
    ll low=(a-b+1);
    ll high=(a+b-1);
    //cerr<<low<< " "<<high;
    ll ans=0;
    ll num;
    while(low<=high) {
        ll mid=(low+high)/2;
        if(mid>=a) {
            ll val=(a+b-mid);
            if(val>ans) {
                ans=val;
                num=mid;
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        else if(mid>=b&&mid<a) {
            ll val=(b+mid-a);
            if(val>ans) {
                ans=val;
                num=mid;
            }
            else {
                high=mid-1;
            }
        }
    }
    cout<<num<<endl;
    return 0;
}
