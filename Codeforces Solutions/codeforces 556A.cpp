#include<bits/stdc++.h>
using namespace std;

void calc(int n,string &str){

    int ans=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='0'||str[i]=='1') ans++;
    }
    cout<<ans<<endl;
    return;
}
void solve(int n,string &str){

    bool more=false;
    for(int i=0;i<str.size()-1;i++){
        if(str[i]=='0'&&str[i+1]=='1'){
            str.erase(i,i+2);
        }
         else if(str[i]=='1'&&str[i+1]=='0'){
            str.erase(i,i+2);
        }
    }
    cout<<str<<" "<<str.size()<<endl;
    if(str.size()>1)  return solve(n,str);
   // else calc(n,str);

}
int main(){
    int n;
    string str;
    cin>>n;
    cin>>str;
    solve(n,str);
    return 0;
}
