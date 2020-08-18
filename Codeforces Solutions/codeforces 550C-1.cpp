#include<bits/stdc++.h>
using namespace std;

bool check(string &temp,int n) {
    int res=0;
    for(int i=0;i<temp.size();i++) {
        res=(res*10+(temp[i]-'0'))%n;
    }
    if(res==0) return true;
    return false;
}
int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    str="00"+str;
    for(int i=0;i<str.size();i++) {
        for(int j=i+1;j<str.size();j++) {
            for(int k=j+1;k<str.size();k++) {
               string temp="";
               //temp+=str[i]; temp+=str[j]; temp+=str[k];
               int val=(str[i]-'0')*100+(str[j]-'0')*10+(str[k]-'0');
               /*if(check(temp,8)) {
                cout<<"YES"<<endl;
                cout<<temp<<endl;
                return 0;
               }*/
               if(val%8==0) {
                cout<<"YES"<<endl;
                cout<<val<<endl;
                return 0;
               }
               //cout<<temp<<endl;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
