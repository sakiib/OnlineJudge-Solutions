#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n,m;
    cin>>n>>m;
    map<string,string> ans;
    while(m--) {
        string f,s;
        cin>>f>>s;
        int l1,l2;
        l1=f.size();
        l2=s.size();
        if(l1==l2) ans[f]=f,ans[s]=f;
        else if(l1<l2) ans[f]=f,ans[s]=f;
        else ans[f]=s,ans[s]=s;
    }
    while(n--) {
        string str;
        cin>>str;
        cout<<ans[str]<< " ";
    }
    return 0;
}
