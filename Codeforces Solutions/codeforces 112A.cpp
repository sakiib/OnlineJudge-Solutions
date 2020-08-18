#include<bits/stdc++.h>
using namespace std;

string conv(string &str){
    for(int i=0;i<str.size();i++){
        if(str[i]>='a'&&str[i]<='z') str[i]-=32;
    }
    return str;
}
int main(){
    string a,b,x,y;
    cin>>a>>b;
    x=conv(a);
    y=conv(b);
    for(int i=0;i<x.size();i++){
        if(a[i]<b[i]){
            cout<<-1<<endl;
            return 0;
        }
        else if(a[i]>b[i]){
            cout<<1<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
