#include<bits/stdc++.h>
using namespace std;

string solve(string &a,string &b){
    string ans="";
    for(int i=0;i<a.size();i++){
        (a[i]==b[i])? ans+='0':ans+='1';
    }
    return ans;
}
int main(){
    string a,b;
    cin>>a>>b;
    cout<<solve(a,b);
    return 0;
}
