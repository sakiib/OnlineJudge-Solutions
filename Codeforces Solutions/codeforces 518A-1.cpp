#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s,t;
    cin>>s>>t;
    for(int i=s.size()-1;i>=0;i--) {
        if(s[i]!='z') {
            s[i]++;
            for(int j=i+1;j<=s.size()-1;j++) {
                s[j]='z';
            }
            break;
        }
    }
    if(s==t) cout<<"No such string"<<endl;
    else cout<<s<<endl;
    return 0;
}
