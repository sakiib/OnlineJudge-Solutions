#include<bits/stdc++.h>
using namespace std;

int main(){
    string str,S="CODEFORCES";
    cin>>str;
    int j=0,cnt=0;
    bool found=false;
    vector<string> V;
    for(int i=0;i<str.size();i++){
        if(S[j]==str[i]){
            j++;
            str[i]='1';
            cnt=1;
        }
    }
    cout<<str<<endl;
    string temp="";
    for(int i=0;i<str.size();i++){
        if(str[i]>='A'&&str[i]<='Z') temp+=str[i];
        else {
            if(temp!="") V.push_back(temp);
            temp="";
        }
    }
    if(temp!="") V.push_back(temp);
    if(V.size()>1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
