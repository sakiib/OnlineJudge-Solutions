#include<bits/stdc++.h>
using namespace std;

map<pair<string,string>,bool> M;

int main(int argc,char const *argv[]) {
         int n;
         cin>>n;
         int ans=0;
         for(int i=1;i<=n;i++) {
            string a,b;
            cin>>a>>b;
            if(!M[{a,b}]) {
                ans++;
                M[{a,b}]=true;
            }
         }
         cout<<ans<<endl;
         return 0;

}
