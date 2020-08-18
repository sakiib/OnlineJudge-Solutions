#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,h;
    cin>>n>>h;
    int ans=0;
    for(int i=1;i<=n;i++) {
        int val;
        cin>>val;
        if(val>h) ans+=2;
        else ans++;
    }
    cout<<ans<<endl;
    return 0;
}
