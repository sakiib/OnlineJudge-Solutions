#include<bits/stdc++.h>
using namespace std;

bool opening(char ch) {
    if(ch=='<'||ch=='{'||ch=='('||ch=='[') return true;
    return false;
}
bool closing(char ch) {
    if(ch=='>'||ch=='}'||ch==')'||ch==']') return true;
    return false;
}
bool matching(char x,char y) {
    if(x=='<'&&y=='>') return true;
    if(x=='('&&y==')') return true;
    if(x=='{'&&y=='}') return true;
    if(x=='['&&y==']') return true;
    return false;
}
int main(int argc,char const *argv) {
    string str;
    cin>>str;
    stack<char> st;
    int ans=0;
    bool impossible=false;
    for(int i=0;i<str.size();i++) {
        if (opening(str[i])) {
            st.push(str[i]);
        }
        else if(closing(str[i])) {
            if(st.empty()) {
                impossible=true;
                break;
            }
            else {
                if(matching(st.top(),str[i])) st.pop();
                else {st.pop(); ans++;}
            }
        }
    }
    if(impossible||!st.empty()) cout<<"Impossible"<<endl;
    else cout<<ans<<endl;

    /*cerr<<st.size()<<endl;
    while(!st.empty()) {
        char x=st.top();
        cerr<<x<<endl;
        st.pop();
    }*/
    return 0;
}
