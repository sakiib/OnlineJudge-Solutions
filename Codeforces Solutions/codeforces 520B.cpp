#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n,m;
    cin>>n>>m;
    if(n>m) {
        cout<<n-m<<endl;
        return 0;
    }
    int ans=0;
    while(m>n) {
        if(m%2==1) {
            ans++;
            m++;
        }
        else {
            m/=2;
            ans++;
        }
    }
    ans+=(n-m);
    cout<<ans<<endl;
    return 0;
}
