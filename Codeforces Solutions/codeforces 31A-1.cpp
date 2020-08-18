#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[1000];
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            for(int k=j+1;k<=n;k++) {
                if(ara[i]==ara[j]+ara[k]) {
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    return 0;
                }
                else if(ara[j]==ara[i]+ara[k]) {
                    cout<<j<<" "<<i<<" "<<k<<endl;
                    return 0;
                }
                else if(ara[k]==ara[i]+ara[j]) {
                    cout<<k<<" "<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}
