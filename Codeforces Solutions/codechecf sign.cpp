#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *rgv[]) {
    int t;
    cin>>t;
    getchar();
    while(t--) {
        string str;
        cin>>str;
        vector<char> V;
        V.clear();
        for(int i=0;i<str.size();i++) {
            if(str[i]=='<'||str[i]=='>') V.push_back(str[i]);
        }
        if(V.size()==0) {
            cout<<1<<endl; continue;
        }
        char ch=V[0];
        int res=0; int cnt=0;
        for(int i=1;i<V.size();i++) {
            if(V[i]==ch) {
                cnt++;
                res=max(res,cnt);
            }
            else {
                cnt=0;
                ch=V[i];
            }
        }
        cout<<res+2<<endl;

    }
    return 0;
}
