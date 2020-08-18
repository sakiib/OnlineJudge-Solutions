#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010];
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    sort(ara+1,ara+n+1);
    int st=ara[1];
    int cnt=1;
    bool found=false;
    for(int i=1;i<=n;i++) {
        if(ara[i]>st+6) {
            cnt++;
            //cerr<<ara[i]<<endl;
            st=ara[i];
            found=true;
        }
        else found=false;
    }
    cout<<cnt<<endl;
    return 0;
}
