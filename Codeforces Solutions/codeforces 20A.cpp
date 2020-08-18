#include<bits/stdc++.h>
using namespace std;

string solve(string &str){
    bool found=false;
    string ret="";
    for(int i=0;i<str.size();i++){
        if(str[i]=='/'&&!found) found=true,ret+='/';
        if(found&&(i!=str.size()-1)){
            if(str[i]>='a'&&str[i]<='z') found=false,ret+=str[i];
        }
        else  ret+=str[i];
    }
    string s="";
    int ind;
    reverse(ret.begin(),ret.end());
    for(int i=0;i<ret.size();i++){
        if(ret[i]!='/') {
            ind=i; break;
        }
    }
    for(int i=ind;i<ret.size();i++){
        s+=ret[i];
    }
    reverse(s.begin(),s.end());
    return s;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string str,ans;
    cin>>str;
    bool ase=false;
    for(int i=0;i<str.size();i++){
        if(str[i]>='a'&&str[i]<='z'){
            ase=true; break;
        }
        else ase=false;
    }
    if(!ase) {
        cout<<"/";
        return 0;
    }
    ans=solve(str);
    cout<<ans<<endl;
    return 0;
}
