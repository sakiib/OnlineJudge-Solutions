#include<bits/stdc++.h>
using namespace std;

bool solve(string &str,int len)
{
    bool yes=true;
    bool dot=true;

    if(str[0]=='T'||str[str.size()-1]=='H') return false;

    for(int i=0;i<str.size();i++){
        if(str[i]=='.') continue;
        else {
            dot=false; break;
        }
    }
    if(dot) return true;

    if(str.size()%2!=0) return false;

    for(int i=0;i<str.size()-1;i+=2){
        if(str[i]=='H'&&str[i+1]=='T') continue;
        else {
            yes=false; break;
        }
    }
    if(yes) return true;

    else return false;

}
int main()
{
    int t,l;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&l);

        string str,a="";
        cin>>str;

        for(int i=0;i<str.size();i++){
            if(str[i]!='.') a+=str[i];
        }
       // cout<<a<<endl;
        if(solve(a,l)) puts("Valid");

        else puts("Invalid");
    }
    return 0;
}
