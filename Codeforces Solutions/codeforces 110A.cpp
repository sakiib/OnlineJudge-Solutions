#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc,char const *argv[]) {
    ll n;
    cin>>n;
    ll cnt=0;
    while(n!=0) {
        if((n%10)==4||(n%10)==7) cnt++;
        n=n/10;
    }
    puts((cnt==4||cnt==7) ? "YES" : "NO");
    return 0;
}
