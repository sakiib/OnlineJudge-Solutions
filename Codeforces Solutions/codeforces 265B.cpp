#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010];
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    int ans=0;
    int temp=0;
    for(int i=1;i<=n;i++) {
        ans+=abs(ara[i]-temp);
        temp=ara[i];
    }
    cout<<ans+2*n-1<<endl;
    return 0;
}
