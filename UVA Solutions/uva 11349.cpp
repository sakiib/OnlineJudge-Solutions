#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
LL ara[105][105];

bool sym() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(ara[i][j]!=ara[n-i-1][n-j-1]) return false;
        }
    }
    return true;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    cin>>t;
    for(tc=1;tc<=t;tc++) {
        string str;
        cin>>str; cin>>str;
        cin>>n;
        bool neg=false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>ara[i][j];
                if(ara[i][j]<0) neg=true;
            }
        }
        if(sym()&&!neg) printf("Test #%d: Symmetric.\n",tc);
        else printf("Test #%d: Non-symmetric.\n",tc);
    }
    return 0;
}
