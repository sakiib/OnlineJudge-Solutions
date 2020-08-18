#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string a; cin>>a;
    int n; cin>>n;
    set<string> S;
    char str[105][105];
    for(int i=1;i<=n;i++) {
        cin>>str[i];
        string temp=str[i];
        string take="";
        if(temp.find(a)!=string::npos) {
            //cout<<temp.find(a)<<endl;
            int ind=temp.find(a);
            for(int i=ind;i<temp.size();i++) {
                take+=temp[i];
            }
            S.insert(take);
        }
    }
    if(S.empty()){cout<<a<<endl; return 0;}
    set<string> :: iterator it;
    for(it=S.begin();it!=S.end();it++) {
        string x=*it;
        cout<<x<<endl;
        break;
    }
    return 0;
}
