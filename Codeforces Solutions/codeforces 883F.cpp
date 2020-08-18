#include<bits/stdc++.h>
using namespace std;

set<string> S;

void solve_b(string &s){
    for(int i=1;i<(int)s.size();i++) {
        if(s[i-1]=='k'&&s[i]=='h') {
            s.erase(i,1);
            s[i-1]='h';
            solve_b(s);
        }
    }
    S.insert(s);
}
string solve_a(string &str) {
    for(int i=0;i<(int)str.size();i++) {
        if(str[i]=='u') {
            str[i]='o';
            str.insert(i,"o");
        }
    }
    return str;
}
int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        string str;
        cin>>str;
        string s=solve_a(str);
        solve_b(s);
    }
    printf("%d\n",(int)S.size());
    return 0;
}
