#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string str;
    int tc;
    for(tc=1; ; tc++) {
        cin>>str;
        if(str[0]=='-') break;
        int len=str.size()/2;
        int l=0,r=0;
        int ans=0;
        for(int i=0;i<str.size();i++) {
            if(str[i]=='{') {
                r++;
                if(r>len) {
                    r--;
                    l++;
                    str[i]='}';
                    ans++;
                }
            }
            else {
                l++;
                if(l>r) {
                    r++;
                    l--;
                    str[i]='{';
                    ans++;
                }
            }
        }
        //cout<<str<<endl;
        cout<<tc<<". "<<ans<<endl;
    }
    return 0;
}
