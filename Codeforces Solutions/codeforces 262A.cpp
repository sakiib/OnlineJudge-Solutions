#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    int ara[1010];
    for(int i=0;i<n;i++) {
        cin>>ara[i];
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        int cnt=0;
        while(ara[i]!=0) {
            int x=ara[i]%10;
            if(x==4||x==7) cnt++;
            ara[i]=ara[i]/10;
        }
        if(cnt<=k) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
