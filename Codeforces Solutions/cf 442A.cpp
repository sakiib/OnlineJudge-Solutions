#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    string a="Danil"; string b="Olya";
    string c="Slava"; string d="Ann";
    string e="Nikita"; str+="XXXXXXXX";
    int k=0;
    for(int i=0;i<str.size()-3;i++) {
        if(str.substr(i,5)==a) k++;
        if(str.substr(i,5)==c) k++;
        if(str.substr(i,4)==b) k++;
        if(str.substr(i,3)==d) k++;
        if(str.substr(i,6)==e) k++;
    }
    if(k==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
