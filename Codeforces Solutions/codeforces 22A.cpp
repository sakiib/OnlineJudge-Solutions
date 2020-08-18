#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[101];
    if(n==1) {
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++) {
        cin>>ara[i];
    }
    sort(ara,ara+n);
    int mn=ara[0];
    for(int i=0;i<n;i++) {
        if(ara[i]!=mn) {
            cout<<ara[i]<<endl;
            return 0;
        }
        if(i==n-1) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    return 0;
}
