#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    int cnt=0;
    for(auto c:str) if(c=='@') cnt++;
    if(cnt==0) {cout<<"No solution"<<endl; return 0;}
    for(int i=0;i<str.size();i++) {
        if(str[i]=='@'&&str[i+1]=='@') {
            cout<<"No solution"<<endl;
            return 0;
        }
    }
    if(str[0]=='@'||str[str.size()-1]=='@') {
        cout<<"No solution"<<endl;
        return 0;
    }
    bool ach=false;
    bool bch=false;
    bool att=false;
    string ans="";
    for(int i=0;i<str.size();i++) {
        if(!bch&&att) {
            cout<<"No solution"<<endl;
            return 0;
        }
        if(str[i]>='a'&&str[i]<='z'&&att) {
            ach=true;
            ans.push_back(str[i]);
        }
        if(str[i]>='a'&&str[i]<='z'&&!att) {
            bch=true;
            ans.push_back(str[i]);
        }
        if(str[i]=='@') att=true,ans.push_back(str[i]);
        if(bch&&att&&ach) {
            cnt--;
            if(cnt<=0) continue;
            if(i!=str.size()-1) ans.push_back(',');
            att=false; ach=false; bch=false;
        }

    }
    if(att&&!bch) {
        cout<<"NO solution"<<endl;
    }
    else cout<<ans<<endl;
    return 0;
}

