#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    ll a,b,s;
    cin>>a>>b>>s;
    ll mn=(abs(a)+abs(b));
    if(s<mn) {
        cout<<"No"<<endl;
        return 0;
    }
    cerr<<mn<<endl;
    s-=mn;
    cerr<<s;
    if(s%2==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
