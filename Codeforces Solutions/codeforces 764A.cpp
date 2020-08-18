#include<bits/stdc++.h>
using namespace std;

int ara[100005];

int main(int argc,char const *argv[]) {
    int n,m,z;
    cin>>n>>m>>z;
    for(int i=n;i<=z;i+=n) ara[i]++;
    for(int i=m;i<=z;i+=m) ara[i]++;
    int ans=0;
    for(int i=1;i<=z;i++) {
        if(ara[i]==2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

