#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string str;
    while(cin>>str) {
        string temp=str;
        string ans;
        bool found=false;
        if(str=="#") break;
        do {
            if(str!=temp) {
                ans=str;
                found=true;
                break;
            }
        }while(next_permutation(str.begin(),str.end()));
        if(found) {
            cout<<ans<<endl;
        }
        else cout<<"No Successor"<<endl;
    }
    return 0;
}
