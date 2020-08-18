#include<bits/stdc++.h>
using namespace std;

map<char,int> M;

void solve1(string &str,string &temp) {
    for(int i=0;i<str.size();i++) {
        if(str[i]=='?') {
            if(!M[temp[i]]){cout<<"NO"<<endl; return;}
        }
        else if(str[i]!=temp[i]) {cout<<"NO"<<endl; return;}
    }
    cout<<"YES"<<endl;
    return;
}
bool left(int p,string &a,string &temp) {
    for(int i=0;i<p;i++) {
        if(a[i]=='?'&&!M[temp[i]]) return false;
        else if(a[i]!=temp[i]) return false;
    }
    return true;
}
bool right(int p,string &b,string &temp) {
     for(int i=0;i<p;i++) {
        if(b[i]=='?'&&!M[temp[i]]) return false;
        else if(b[i]!=temp[i]) return false;
    }
    return true;
}
int main(int argc,char const *argv[]) {
    string good;
    cin>>good;
    for(auto c: good) {
        M[c]=true;
    }
    string str;
    cin>>str;
    int p=str.find('*');
    string a="",b="";
    if(p!=-1) {
        for(int i=0;i<str.size();i++) {
            if(i<p) a+=str[i];
            if(i>p) b+=str[i];
        }
    }
    int t;
    cin>>t;
    while(t--) {
        string temp;
        cin>>temp;
        if(p==-1) {
            if(str.size()!=temp.size()) cout<<"NO"<<endl;
            else solve1(str,temp);
        }
        else {
            if(left(p,a,temp)&&right(p,b,temp))
                cout<<"YES"<<endl;
            else cout<<"dog"<<"NO"<<endl;
        }
    }
    return 0;
}
