#include<bits/stdc++.h>
using namespace std;

stack <char> st;
int ans=0;

int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    for(auto c:str) {
        if(c=='(') st.push(c);
        else if(c==')') {
            if(st.empty()) continue;
            char k=st.top();
            if(k=='(') {
                ans+=2;
                st.pop();
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
