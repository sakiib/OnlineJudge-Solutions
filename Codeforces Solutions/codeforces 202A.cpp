#include<bits/stdc++.h>
using namespace std;

char largest(string &str) {
    sort(str.begin(),str.end());
    return (str[str.size()-1]);
}
void getans(string &str,char ch) {
    string ret="";
    for(int i=0;i<str.size();i++) {
        if(str[i]==ch) ret+=str[i];
    }
    cout<<ret<<endl;
    return;
}
int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    char ch=largest(str);
    getans(str,ch);
    return 0;
}
