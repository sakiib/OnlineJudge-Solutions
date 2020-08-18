#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    if(str.size()<26) {
        cout<<-1<<endl;
        return 0;
    }
    int ind=0;
    string res="";
    bool found=false;
    for(int i=0;i<=str.size()-26;i++) {
        set<char> S;
        S.clear();
        int cnt=0;
        string temp="";
        for(int j=i;j<26+i;j++) {
           if(str[j]!='?') S.insert(str[j]);
           else cnt++;
           temp+=str[j];
        }
        if(cnt+S.size()==26) {
          //cout<<temp<<endl;
          ind=i;
          found=true;
          for(int k=0;k<temp.size();k++) {
            if(S.find(temp[k])!=S.end()) res+=temp[k];
            else {
                for(char l='A';l<='Z';l++) {
                    if(S.find(l)==S.end()) {
                        res+=l;
                        S.insert(l);
                        break;
                    }
                }
            }
          }
        }
        if(found) break;
    }
    if(!found) {
        cout<<-1<<endl; return 0;
    }
    for(int i=0;i<ind;i++) {
        if(str[i]=='?') cout<<'A';
        else cout<<str[i];
    }
    cout<<res;
    for(int i=ind+26;i<str.size();i++) {
        if(str[i]=='?') cout<<'A';
        else cout<<str[i];
    }
    return 0;
}
