#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc,char const *argv[]) {
    ll n;
    cin>>n;
    ll sq=sqrt(n);
    if(sq*sq==n) {
        cout<<4*sq<<endl;
        return 0;
    }
    ll rem=n-sq*sq;
    if(rem<=sq) cout<<4*sq+2<<endl;
    else cout<<4*sq+4<<endl;
    return 0;
}
