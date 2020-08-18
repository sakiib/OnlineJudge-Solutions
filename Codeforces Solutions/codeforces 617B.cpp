#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010];
    bool found=false;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        if(ara[i]==1) found=true;
    }
    if(!found) {
        cout<<0<<endl; return 0;
    }
    int pos=1;
    ll ans=1;
    vector<int> V;
    for(int i=1;i<=n;i++) {
        if(ara[i]==1) V.push_back(i);
    }
    //for(auto &x : V) cout<<x<< " ";
    if(V.size()==1) cout<<1<<endl;
    else {
        for(int i=1;i<V.size();i++) {
            ans*=(V[i]-V[i-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
