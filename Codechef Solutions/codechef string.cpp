#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv) {
    int t;
    cin>>t;
    getchar();
    while(t--) {
        string a,b;
        int q;
        cin>>a>>b;
        cin>>q;
        string c=a+b;
        sort(c.begin(),c.end());
        while(q--) {
            string s;
            cin>>s;
            sort(s.begin(),s.end());
            if(s==c) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
