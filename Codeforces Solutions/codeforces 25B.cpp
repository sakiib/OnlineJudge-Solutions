#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    string str;
    cin>>str;
    if(n<=2) {
        cout<<str<<endl; return 0;
    }
    if(n%2==0) {
        int k=0;
        int t=n/2;
        for(int i=1;i<=t;i++) {
            if(i!=t) {
                cout<<str.substr(k,2)<<"-";
            }
            else cout<<str.substr(k,2);
            k+=2;
        }
        cout<<endl;
    }
    else {
        int k=0;
        int t=n/2;
        t--;
        for(int i=1;i<=t;i++) {
            cout<<str.substr(k,2)<<"-";
            k+=2;
        }
        cout<<str.substr(k,3)<<endl;
    }
    return 0;
}
