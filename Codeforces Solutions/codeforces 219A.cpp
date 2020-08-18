#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int k;
    cin>>k;
    string str;
    cin>>str;
    if(str.size()%k!=0) {
        cout<<-1<<endl;
        return 0;
    }
    map<char,int> M;
    for(int i=0;i<str.size();i++) {
        M[str[i]]++;
    }
    string ans="";
    map<char,int> :: iterator it;
    for(it=M.begin();it!=M.end();it++) {
        if(it->second%k!=0) {
            cout<<-1<<endl;
            return 0;
        }
        int t=(it->second/k);
        while(t--) {
            ans+=it->first;
        }
    }
    while(k--) {
        cout<<ans;
    }
    return 0;
}
