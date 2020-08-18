#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    ll t;
    cin>>t;
    while(t--) {
        vector<ll> a;
        a.clear();
        char ch;
        ll num;
        while(scanf("%lld%c",&num,&ch)) {
            a.push_back(num);
            if(ch=='\n') break;
        }
        for(int i=0;i<a.size();i++) {
            if(a[i]==(a.size()-1)) {a[i]=-1; break;}
        }
        sort(a.rbegin(),a.rend());
        cout<<a[0]<<endl;
    }
    return 0;
}
