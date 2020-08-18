#include<bits/stdc++.h>
using namespace std;
int ara[1000010];
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>ara[i];
        }
        long long cnt=0;
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                if((ara[i]|ara[j])<=max(ara[i],ara[j])) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
