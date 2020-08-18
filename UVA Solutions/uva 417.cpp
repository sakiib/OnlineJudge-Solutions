#include<bits/stdc++.h>
using namespace std;

map<string,int> M;

void generate_string() {
    queue<string> Q;
    for(char i='a';i<='z';i++) {
        string t="";
        t+=i;
        Q.push(t);
    }
    int val=1;
    while(!Q.empty()) {
        string top=Q.front();
        Q.pop();
        M[top]=val++;
        if(top.size()==5) continue;
        for(char i=top[top.size()-1]+1;i<='z';i++) {
            Q.push(top+i);
        }
    }
}
int main(int argc,char const *argv[]) {
    generate_string();
    string str;
    while(cin>>str) {
        cout<<M[str]<<endl;
    }
    return 0;
}
