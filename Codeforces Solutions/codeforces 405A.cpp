#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const argv[]) {
    int n,ara[100010];
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    sort(ara+1,ara+n+1);
    for(int i=1;i<=n;i++) {
        cout<<ara[i]<< " ";
    }
    return 0;
}
