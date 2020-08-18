#include<bits/stdc++.h>
using namespace std;

map<char,int> M;

bool check(string str) {
    int k=0;
    for(int i=0;i<str.size();i++) {
        k=(k*10+(str[i]-'0'))%7;
    }
    if(k==0) return true;
    return false;
}
void get_ans(string &temp,int mn,int zero) {
    string a="1869";
    for(int i=1;i<=mn;i++) cout<<a;
    cout<<temp;
    for(int i=1;i<=zero;i++) cout<<"0";
    cout<<endl;
    exit(0);
}
int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    for(auto c:str) M[c]++;
    int mn=min(M['1'],min(M['8'],min(M['6'],M['9'])));
    //cout<<"mn : "<<mn<<endl;
    if(mn==0) {
        cout<<0<<endl; return 0;
    }
    if(M['1']<mn||M['8']<mn||M['6']<mn||M['9']<mn) {
        cout<<0<<endl; return 0;
    }
    //cout<<M['1']<<" "<<M['8']<<" "<<M['6']<<" "<<M['9']<<endl;
    M['1']-=mn; M['8']-=mn;
    M['6']-=mn; M['9']-=mn;
    //cout<<M['1']<<" "<<M['8']<<" "<<M['6']<<" "<<M['9']<<endl;
    string temp="";
    int zero=0;
    for(auto x:M) {
        if(x.first=='0') {zero+=x.second; continue;}
        for(int i=0;i<x.second;i++) {
            temp+=x.first;
        }
    }
    //cout<<temp<<" "<<zero<<endl;
    sort(temp.begin(),temp.end());
    do{
        if(check(temp)) get_ans(temp,mn,zero);
    }
    while(next_permutation(temp.begin(),temp.end()));
    cout<<0<<endl;
    return 0;
}
