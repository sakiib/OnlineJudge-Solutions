#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll check(ll a,ll b) {
    ll ans=a;
    while(a) {
        ans+=(a/b);
        //b*=b;
        a/=b;
    }
    return ans;
}
int main(int argc,char const *argv[]) {
    ll n,k;
    cin>>n>>k;
    ll low=1,high=n,mid;
    while(low<=high) {
        mid=(low+high)/2;
        if(check(mid,k)>=n) high=mid-1;
        else low=mid+1;
    }
    cout<<low<<endl;
    return 0;
}
