#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    int ara[100010];
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        ara[i]+=k;
    }
    sort(ara+1,ara+n+1);
    int cnt=0;
    /*for(int i=1;i<=n;i++) {
        cout<<ara[i]<< " ";
    }*/
    for(int i=1;i<=n;i++) {
        if(ara[i]>5) break;
        else cnt++;
    }
    //cout<<cnt<<endl;
    cout<<cnt/3<<endl;
    return 0;
}
