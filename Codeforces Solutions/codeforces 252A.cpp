#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,ara[1000];
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>ara[i];
    }
    int mx=0;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            int a=0;
            for(int k=i;k<=j;k++) {
                a^=ara[k];
            }
            mx=max(mx,a);
        }
    }
    cout<<mx<<endl;
    return 0;
}
