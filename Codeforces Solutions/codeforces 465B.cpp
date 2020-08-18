#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010];
    bool found=false;
    int cnt=0;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        if(ara[i]==1) {found=true; cnt++;}
    }
    if(!found) {
        cout<<0<<endl;
        return 0;
    }
    bool zer=false;
    int st,en;
    for(int i=1;i<=n;i++) {
        if(ara[i]==1){
            st=i; break;
        }
    }
    for(int i=n;i>=1;i--) {
        if(ara[i]==1) {
            en=i; break;
        }
    }
    for(int i=st;i<=en;i++) {
        if(ara[i]==0&&!zer) {
            zer=true;
            cnt++;
        }
        if(ara[i]==1) {
            zer=false;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
