#include<bits/stdc++.h>
using namespace std;
int ara[1000100];
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    bool odd=false;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        if(ara[i]&1) odd=true;
    }
    if(!odd) {
        cout<<"Second"<<endl;
        return 0;
    }
    else cout<<"First"<<endl;
    return 0;
}

