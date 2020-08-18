#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    int ara[10];
    for(int i=1;i<=7;i++) {
        cin>>ara[i];
    }

    int s=0,cnt=0;

    while(true) {
        for(int i=1;i<=7;i++) {
            if(ara[i]!=0) {
                s+=ara[i];
            }
            if(s>=t) {
                cout<<i<<endl;
                return 0;
            }
        }
    }
    return 0;
}
