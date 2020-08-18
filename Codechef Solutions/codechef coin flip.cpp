#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        int game;
        cin>>game;
        while(game--) {
            int in,n,q;
            cin>>in>>n>>q;
            if(n%2==0) {
                cout<<n/2<<endl;
            }
            else {
                if(in==q) cout<<n/2<<endl;
                else cout<<n/2+1<<endl;
            }
        }
    }
    return 0;
}
