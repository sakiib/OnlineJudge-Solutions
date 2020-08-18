#include<bits/stdc++.h>
using namespace std;

string vowel(string &str){
    string ret="";
    for(int i=0;i<str.size();i++){
        if(str[i]!='a'&&str[i]!='A'&&str[i]!='e'&&str[i]!='E'
           &&str[i]!='i'&&str[i]!='I'&&str[i]!='o'&&str[i]!='O'
           &&str[i]!='u'&&str[i]!='U'&&str[i]!='y'&&str[i]!='Y') ret+=str[i];
    }
    return ret;
}
string con(string &S){
    for(int i=0;i<S.size();i++){
        if(S[i]>='A'&&S[i]<='Z') S[i]+=32;
    }
    return S;
}
void solve(string &N){
    for(int i=0;i<N.size();i++){
        if(i<N.size()) putchar('.');
        cout<<N[i];
    }
}
int main(){
    string str,S,N;
    cin>>str;
    S=vowel(str);
    N=con(S);
    solve(N);
    return 0;
}
