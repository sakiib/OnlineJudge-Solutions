#include<bits/stdc++.h>
using namespace std;

void prin(int a,string &str) {
    for(int i=0;i<a;i++) {
        cout<<str[i];
    }
    cout<<endl;
    exit(0);
}
void rev(int r,string &str) {
    reverse(str.begin(),str.end());
    for(int i=0;i<r;i++) {
        cout<<str[i];
    }
    cout<<endl;
    exit(0);
}
int main(int argc,char const *argv[]) {
    string str;
    int ind,x=0,y=0;
    cin>>str;
    sort(str.begin(),str.end());
    //cout<<str;
    for(int i=0;i<str.size();i++) {
        if(str[i]=='x') x++;
        else y++;
    }
    if(x>y) prin(x-y,str);
    else rev(y-x,str);
    return 0;
}
