#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[105];
    for(int i=1;i<=n;i++) cin>>ara[i];
    if(ara[1]%2==0||ara[n]%2==0) {
        cout<<"NO"<<endl;
        return 0;
    }
    if(n&1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
