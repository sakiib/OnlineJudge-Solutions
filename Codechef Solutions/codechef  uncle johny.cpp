#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t,n,ara[100010],k;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>ara[i];
        }
        cin>>k;
        int temp=ara[k];
        sort(ara+1,ara+n+1);
        for(int i=1;i<=n;i++) {
            if(ara[i]==temp) {
                cout<<i<<endl; break;
            }
        }
    }
    return 0;
}
