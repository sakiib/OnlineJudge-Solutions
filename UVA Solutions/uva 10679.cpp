#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        int q;
        cin>>q;
        while(q--) {
            string s;
            cin>>s;
            int l=s.size();
            if(str.substr(0,l)==s) cout<<"y"<<endl;
            else cout<<"n"<<endl;
        }
    }
    return 0;
}
