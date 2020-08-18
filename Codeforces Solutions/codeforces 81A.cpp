#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    string ans="";
    stack<char> st;
    st.push('X');
    for(int i=0;i<str.size();i++) {
        if(st.top()!=str[i]) {
            st.push(str[i]);
        }
        else {
            st.pop();
        }
    }
    while(!st.empty()) {
        char x=st.top();
        ans+=x;
        st.pop();
    }
    cerr<<ans<<endl;
    reverse(ans.begin(),ans.end());
    for(int i=1;i<ans.size();i++) {
        cout<<ans[i];
    }
    return 0;
}
