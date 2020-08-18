#include<bits/stdc++.h>
using namespace std;
int solve_mx(string &a,string &b)
{
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if((a[i]!=b[i])||(a[i]=='?'||b[i]=='?')) cnt++;
    }
    return cnt;
}
int solve_mn(string &a,string &b)
{
    int ans=0,w;
    for(int i=0;i<a.size();i++){
       if((a[i]!=b[i])&&(a[i]!='?'||b[i]!='?')&&(a[i]!='?'&&b[i]!='?')) ans++;
    }
    return ans;
}
int main()
{
    int t,mn,mx;
    cin>>t;
    string a,b;
    while(t--){
        cin>>a>>b;
        mn=solve_mn(a,b);
        mx=solve_mx(a,b);
        cout<<mn<< " " <<mx<<endl;
    }
    return 0;
}
