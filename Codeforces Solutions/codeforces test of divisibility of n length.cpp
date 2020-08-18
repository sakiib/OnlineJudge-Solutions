#include<bits/stdc++.h>
using namespace std;
//checking for 23//
int main(int argc,char const *argv[]) {
    int n,t=23,x=15;
    cin>>n;
    if(n<2) {
        cout<<-1<<endl;
        return 0;
    }
    if(n==2) {
        cout<<23<<endl;
        return 0;
    }
    cout<<1;
    for(int i=1;i<=n-3;i++) {
        cout<<0;
        x*=10;
        x%=23;
    }
    printf("%02d",x);
    return 0;
}
