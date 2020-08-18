#include<bits/stdc++.h>
using namespace std;
int ara[200010];
int keep[200010]={0};
int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    for(int i=1;i<=n;i++) {
        ara[i]+=ara[i-1];
    }
    /*for(int i=1;i<=n;i++) {
        cout<<ara[i]<<endl;
    }*/
    int mx=(int)(1e9);
    int ind;
    for(int i=k;i<=n;i++) {
        //cout<<ara[i]-ara[i-k]<<endl;
        if(ara[i]-ara[i-k]<mx) {
            mx=ara[i]-ara[i-k];
            ind=i-k+1;
        }
    }
    cout<<ind<<endl;
    return 0;
}
