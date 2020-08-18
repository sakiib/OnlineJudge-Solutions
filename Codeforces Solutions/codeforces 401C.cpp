#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int zero,one;
    cin>>zero>>one;
    if(one>zero*3) {
        cout<<-1<<endl; return 0;
    }
    if(zero==one) {
        for(int i=1;i<=(zero+one);i++) {
            if(i&1) cout<<1;
            else cout<<0;
        }
        return 0;
    }
    if(zero*3==one) {
        for(int i=1;i<=one;i+=2) {
            cout<<"11";
            if(i!=one-1) cout<<0;
        }
        return 0;
    }
    if(zero>one) {
        if(one+1<zero) {
            cout<<-1<<endl; return 0;
        }
    }
}
