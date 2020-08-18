#include<bits/stdc++.h>
using namespace std;

void solve(string &str){
    int a=0,b=0,mx=-1;
    for(int i=0;i<str.size();i++){
        if(str[i]=='0'){
            a++;
            b=0;
            mx=max(mx,a);
        }
        if(str[i]=='1'){
            b++;
            a=0;
            mx=max(mx,b);
        }
    }
   // cout<<mx<<endl;
    (mx>=7)?cout<<"YES":cout<<"NO";
}
int main(){

    string str;
    cin>>str;
    solve(str);
    return 0;
}
