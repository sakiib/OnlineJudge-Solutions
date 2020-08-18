#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010];
    int mx=0;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        mx=max(mx,ara[i]);
    }
    cout<<mx<<endl;
    return 0;
}
