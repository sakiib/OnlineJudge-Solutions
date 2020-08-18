#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    ll t;
    cin>>t;
    while(t--) {
        int n,a,b;
        cin>>n>>a>>b;
        if(a>b) swap(a,b);
        int one=max(a,b)-min(a,b)-1;
        int other=n-one-2;
        //cerr<<one<<" "<<other<<endl;
        if(one<other) cout<<one<<endl;
        else if(other<one) cout<<other<<endl;
        else cout<<0<<endl;
    }
    return 0;
}

