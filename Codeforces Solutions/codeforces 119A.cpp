#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int a,b,n;
    cin>>a>>b>>n;
    while(true) {
        int x=__gcd(a,n);
        if(x<=n) n-=x;
        else {
            cout<<1<<endl; return 0;
        }
        int y=__gcd(b,n);
        if(y<=n) n-=y;
        else {
            cout<<0<<endl; return 0;
        }
    }
    return 0;
}
