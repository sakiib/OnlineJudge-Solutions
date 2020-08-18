#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int t,tc;
   cin>>t;
   for(tc=1;tc<=t;tc++) {
     int n,m;
     cin>>n>>m;
     char str[105][105];
     for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%c",&str[i][j]);
        }
        getchar();
     }
     string ans="";
     set<string> S;
     S.clear();
     for(int i=0;i<n;i++) {
        ans="";
        for(int j=0;j<m;j++) {
            if(str[i][j]=='X') {
                if(ans.size()>=2) S.insert(ans);
                ans="";
            }
            else ans+=str[i][j];
        }
        if(ans.size()>=2) S.insert(ans);
     }
     for(int i=0;i<m;i++) {
        ans="";
        for(int j=0;j<n;j++) {
            if(str[j][i]=='X') {
                if(ans.size()>=2) S.insert(ans);
                ans="";
            }
            else ans+=str[j][i];
        }
        if(ans.size()>=2) S.insert(ans);
     }
     string res;
     for(auto &x : S) {
        res=x;
        break;
     }
     cout<<"Case "<<tc<<": "<<res<<endl;
   }
   return 0;
}
