#include<bits/stdc++.h>
using namespace std;
string trail(string &str)
{
    int p;
    string ret="";
    for(int i=0;i<str.size();i++){
        if(str[i]!='0'){
            p=i; break;
        }
    }
    for(int i=p;i<str.size();i++){
        ret+=str[i];
    }
    return ret;
}
string solve(string &c,string &d)
{
    int l1,l2;
    l1=c.size();
    l2=d.size();
    while(l1<l2){
        c+='0';
        l1++;
    }
    while(l2<l1){
        d+='0';
        l2++;
    }
    //cout<<c<< " "<<d<<endl;
    for(int i=c.size();i>=0;i--){
        if(c[i]<d[i]) return "<";
        else if(c[i]>d[i]) return ">";
    }
    return "=";

}
 int main()
 {
     ios_base::sync_with_stdio(false);
     string a,b,c,d,ans;
     cin>>a>>b;
     c=trail(a);
     d=trail(b);
     //cout<<c<< " "<<d;
     reverse(c.begin(),c.end());
     reverse(d.begin(),d.end());
     ans=solve(c,d);
     cout<<ans<<endl;
     return 0;
 }
