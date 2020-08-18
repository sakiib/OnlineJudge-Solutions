#include<bits/stdc++.h>
using namespace std;

set<string> word;
set<char> ch;
set<string> temp;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        for(int i=0;i<=s.size();i++) {
            for(int j=0;j<=s.size();j++) {
                temp.insert(s.substr(i,j));
            }
        }
        word.insert(s);
        for(auto c:s) ch.insert(c);
    }
    if((int)ch.size()<26) {
        for(char i='a';i<='z';i++) {
            if(ch.find(i)==ch.end()) {
                cout<<i<<endl;
                return 0;
            }
        }
    }
    for(char i='a';i<='z';i++) {
        for(char j='a';j<='z';j++) {
            string ans;
            ans+=(i);
            ans+=(j);
            //cout<<ans<<endl;
            if(temp.find(ans)==temp.end()) {
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    return 0;
}
