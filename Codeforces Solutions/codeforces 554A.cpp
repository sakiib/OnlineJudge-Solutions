#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

    set<char> S;
    string str;
    cin>>str;

    ll ans=str.size();
    ll l=str.size();
    ans=26-ans;
    ll s=26;
    for(int i=0;i<l-1;i++){
        s+=26;
    }
    cout<<s+ans;
    return 0;
}
