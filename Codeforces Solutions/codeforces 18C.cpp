#include<bits/stdc++.h>
using namespace std;

int ara[100010];
int f[100010],b[100010];

int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    for(int i=1;i<=n;i++) {
        f[i]=ara[i]+f[i-1];
    }
    /*for(int i=1;i<=n;i++) {
        cout<<f[i]<< " ";
    }*/
    for(int i=n;i>=1;i--) {
        b[i]=ara[i]+b[i+1];
    }
    /*for(int i=n;i>=1;i--) {
        cout<<b[i]<< " ";
    }*/
    int ans=0;
    for(int i=1;i<n;i++) {
        if(f[i]==b[i+1]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
