#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++) {
        if(str[i]>='A'&&str[i]<='Z') str[i]+=32;
    }
    cerr<<str<<endl;
    int ara[30]={0};
    for(auto c:str) {
       ara[c-'a']=1;
    }
    for(char i='a';i<='z';i++) {
        if(ara[i-'a']!=1) {
            cout<<"NO"<<endl; return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
