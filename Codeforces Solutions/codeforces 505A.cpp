#include<bits/stdc++.h>
using namespace std;

bool palin(string &str) {

    int l=str.size();
    for(int i=0;i<l/2;i++) {
        if(str[i]!=str[l-i-1]) return false;
    }
    return true;
}
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin>>str;

    if(palin(str)) {

        int k=str.size();
        if(k&1) {
            int a=k/2;
            char ex=str[a];
            for(int i=0;i<a;i++) {
                cout<<str[i];
            }
            cout<<ex;
            for(int i=a;i<str.size();i++) {
                cout<<str[i];
            }
            return 0;
        }
        else {
            int m=str.size()/2;
            for(int i=0;i<str.size();i++) {
                if(i==m) cout<<'x';
                cout<<str[i];
            }
            return 0;
        }
    }
    for(int i=0;i<=str.size();i++) {
        for(char j='a';j<='z';j++) {
            string temp=str.substr(0,i)+string(1,j)+str.substr(i);
            cerr<<str.substr(0,i)<< " "<<string(1,j)<< " "<<str.substr(i)<<endl;
            cout<<temp<<endl;
            if(palin(temp)) {

                cout<<temp<<endl;
                return 0;
            }
        }
    }
    cout<<"NA"<<endl;
    return 0;
}
