#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin>>str;
    str+="WUB";
    bool found=true;
    string k="WUB";
    int j=0;
    string ans="";
    for(int i=0;i<=str.size()-3;) {
        if(str[i]=='W'&&str[i+1]=='U'&&str[i+2]=='B') {
            i+=3;
            ans+=' ';
            continue;
        }
        else ans+=str[i];
        i++;
    }

    string temp="";
    int ind=0;
    for(int i=0;i<ans.size();i++) {
        if(ans[i]!=' '){
            ind=i;
            break;
        }
    }
    for(int i=ind;i<ans.size();i++) {
        temp+=ans[i];
    }
    //cout<<ans<<endl;
    cout<<temp<<endl;
    return 0;
}
