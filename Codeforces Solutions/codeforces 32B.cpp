#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    string ans="";
    for(int i=0;i<str.size();){
        if(str[i]=='.') ans+='0',i++;
        if(str[i]=='-'&&str[i+1]=='.') ans+='1',i+=2;
        if(str[i]=='-'&&str[i+1]=='-') ans+='2',i+=2;
    }
    cout<<ans<<endl;
    return 0;
}
