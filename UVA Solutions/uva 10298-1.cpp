#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {

    string str;
    while(cin>>str) {
        if(str==".") break;
        int res=0;
        for(int i=0;i<str.size();i++) {
            string temp="";
            for(int j=0;j<=i;j++) {
                temp+=str[j];
            }
            //cout<<temp<<endl;
            int k=1;
            int l=str.size();
            int m=temp.size();
            int s=l/m;
            string ans="";
            while(k<=s) {
                ans+=temp;
                k++;
            }
            //cout<<ans<<" "<<str<<endl;
            if(ans==str) {
                res=s;
                //cerr<<ans<<endl;
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
