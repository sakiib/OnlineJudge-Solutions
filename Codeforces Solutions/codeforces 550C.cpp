#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    ll k=0;
    for(ll i=0;i<str.size();i++) {
         k=(k*10+(str[i]-'0'))%8;
         cerr<<"Rem : "<<k<<endl;
    }
    cerr<<k<<endl;
    if(!k) {
        cout<<"YES"<<endl;
        cout<<str<<endl;
        return 0;
    }
}
