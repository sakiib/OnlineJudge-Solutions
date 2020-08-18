#include<bits/stdc++.h>
using namespace std;
int solve(string &str,int l)
{
    int cnt=0;
    for(int i=0;i<l;i++){
        if(str[i]!=str[str.size()-1-i]) cnt++;
        else continue;
    }
    return cnt;
}
int main()
{
    int t,tc,l,len,ans;
    string str;
    cin>>t;
    getchar ();
    for(tc=1;tc<=t;tc++){
        cin>>str;
        l=str.size()/2;
        ans=solve(str,l);
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}
